#include "bits/stdc++.h"
using namespace std;
long long n , m;
long long ans;
int main(){
    cin >> n >> m;
    ans = n;
    long long l = m + 1;
    long long r = m + 2e9;
    while(l < r){
        long long mid = l + r >> 1;
        long long val = mid - m;
        long long tot = m;
        tot += (val * (val + 1LL)) / 2LL;
        if(tot < n){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    ans = min(ans , l);
    printf("%lld\n" , ans);
}