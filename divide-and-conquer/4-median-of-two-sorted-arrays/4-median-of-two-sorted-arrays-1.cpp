class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        
        int n1 = v1.size() , n2 = v2.size();
        
        if(n1 > n2) swap(v1 , v2) , swap(n1 , n2);
        
        int l = 0 , r = n1;
        
        int s = (n1 + n2)/2;
        
        double ans = 0.0;
        
        while(l <= r){
            
            int m1 = l + ((r-l)>>1);
            int m2 = s - m1;
            
            int l1 = m1 > 0 ? v1[m1-1] : -1e6-1;
            int l2 = m2 > 0 ? v2[m2-1] : -1e6-1;
            int r1 = m1 < n1 ? v1[m1] : 1e6 + 1;
            int r2 = m2 < n2 ? v2[m2] : 1e6 + 1;
            
            if(l1 <= r2 and l2 <= r1){
                
                if(!((n1+n2)&1)){
                    ans = (max(l1 , l2) + min(r1 , r2)) / 2.0;
                }
                else{
                    ans = min(r1 , r2);
                }
                break;
            }
            
            else if(l1 > r2){
                r = m1 - 1;
            }
            else l = m1 + 1;
            
        }
        
        return ans;

    }
};