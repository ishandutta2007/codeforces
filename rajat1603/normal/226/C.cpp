#include "bits/stdc++.h"
using namespace std;
long long mod , l , r , k , ans;
void check(long long val){
    for(long long i = max(1LL , val - 1) ; i <= val + 1 ; ++i){
        long long cnt = (r / i) - ((l - 1) / i);
        if(cnt >= k){
            ans = max(ans , i);
        }
    }
}
int main(){
    cin >> mod >> l >> r >> k;
    for(int i = 1 ; 1LL * i * i <= r ; ++i){
        check(i);
        check(r / i);
        check(l / i);
    }
    pair < long long , long long > res = {0 , 1} , base = {1 , 0};
    while(ans){
        if(ans & 1){
            res = {(res.first * (base.second + base.first) + res.second * base.first) % mod , (res.first * base.first + res.second * base.second) % mod};
        }
        base = {(base.first * (base.second + base.first) + base.second * base.first) % mod , (base.first * base.first + base.second * base.second) % mod};
        ans >>= 1;
    }
    cout << res.first;
}