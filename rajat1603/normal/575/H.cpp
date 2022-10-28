#include "bits/stdc++.h"
using namespace std;
const int N = 2e6 + 6;
const int mod = 1e9 + 7;
int add(int a , int b){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int mult(int a , int b){
    long long res = a;
    res *= b;
    if(res >= mod){
        return res % mod;
    }
    return res;
}
int power(int a , int b){
    int res = 1;
    while(b){
        if(b & 1){
            res = mult(res , a);
        }
        a = mult(a , a);
        b >>= 1;
    }
    return res;
}
int fact[N];
int ifact[N];
void pre(){
    fact[0] = 1;
    for(int i = 1 ; i < N ; ++i){
        fact[i] = mult(fact[i - 1] , i);
    }
    ifact[N - 1] = power(fact[N - 1] , mod - 2);
    for(int i = N - 2 ; i >= 0 ; --i){
        ifact[i] = mult(ifact[i + 1] , i + 1);
    }
}
int C(int n , int r){
    return mult(fact[n] , mult(ifact[r] , ifact[n - r]));
}
int n;
int ans = 0;
int main(){
    pre();
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        ans = add(ans , C(n + i , i));
    }
    ans = add(ans , ans);
    cout << add(ans , 1);
}