#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e3 + 3;
int fact[N];
int invfact[N];
int input;
int sum = 0;
int res = 1;
int n;
int power(int a , int b){
    int res = 1;
    while(b){
        res = (b & 1) ? (1LL * res * a) % mod : res;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}
void pre(){
    fact[0] = 1;
    for(int i = 1 ; i < N ; ++i){
        fact[i] = (1LL * fact[i - 1] * i) % mod;
    }
    invfact[N - 1] = power(fact[N - 1] , mod - 2);
    for(int i = N - 2 ; i >= 0 ; --i){
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % mod;
    }
}
int C(int n , int r){
    return (1LL * ((1LL * fact[n] * invfact[r]) % mod) * invfact[n - r]) % mod;
}
int main(){
    pre();
    cin >> n;
    cin >> sum;
    for(int i = 2 ; i <= n ; ++i){
        cin >> input;
        sum += input;
        res = (1LL * res * C(sum - 1 , input - 1)) % mod;
    }
    cout << res;
}