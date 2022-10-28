#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
long long power(long long a , long long b){
    long long res = 1;
    while(b){
        if(b & 1){
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}
long long n;
int main(){
    cin >> n;
    long long ans = power(3 , 3 * n);
    ans -= power(7 , n);
    if(ans < 0){
        ans += mod;
    }
    cout << ans;
}