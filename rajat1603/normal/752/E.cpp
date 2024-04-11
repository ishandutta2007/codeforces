#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , k;
int arr[N];
long long sum;
bool check(int val){
    long long tot = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(val == 1){
            tot += arr[i];
        }
        else if(arr[i] >= val){
            int val1 = arr[i];
            int cnt1 = 1;
            int cnt2 = 0;
            while(cnt1 || cnt2){
                int ncnt1 = 0;
                int ncnt2 = 0;
                int nval1;
                if((val1 >> 1) >= val){
                    nval1 = val1 >> 1;
                    ncnt1 += cnt1;
                    if(val1 & 1){
                        ncnt2 += cnt1;
                    }
                    else{
                        ncnt1 += cnt1;
                    }
                }
                else{
                    nval1 = val1 >> 1;
                    tot += cnt1;
                }
                if(((val1 + 1) >> 1) >= val){
                    ncnt2 += cnt2;
                    if(((val1 + 1) >> 1) == nval1){
                        ncnt1 += cnt2;
                    }
                    else{
                        ncnt2 += cnt2;
                    }
                }
                else{
                    tot += cnt2;
                }
                cnt1 = ncnt1;
                cnt2 = ncnt2;
                val1 = nval1;
            }
        }
    }
    return tot >= k;
}
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        sum += arr[i];
    }
    if(sum < k){
        printf("-1\n");
    }
    else{
        int l = 1;
        int r = min(sum / k , 10000000LL);
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(check(mid)){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        printf("%d\n" , l);
    }
}