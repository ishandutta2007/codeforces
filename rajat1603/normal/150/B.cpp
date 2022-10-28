#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
int n , m , k;
long long ans = 1;
int power;
int main(){
    cin >> n >> m >> k;
    if(k == 1 || k > n){
        power = n;
    }
    else if(k == n){
        power = (n >> 1) + (n & 1);
    }
    else if(k & 1){
        power = 2;
    }
    else{
        power = 1;
    }
    while(power--){
        ans *= m;
        ans %= mod;
    }
    cout << ans;
}