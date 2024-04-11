#include "bits/stdc++.h"
using namespace std;
const int K = 1e6 + 6;
const int mod = 1e9 + 7;
int n , k;
int val[K];
int ans , cur;
int power(int a , int b){
    int res = 1;
    while(b){
        if(b & 1){
            res = (1LL * res * a) % mod;
        }
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= k + 2 ; ++i){
        val[i] = (val[i - 1] + power(i , k)) % mod;
    }
    if(n <= k + 2){
        printf("%d\n" , val[n]);
        return 0;
    }
    ans = 0;
    cur = 1;
    for(int i = 2 ; i <= k + 2 ; ++i){
        cur = (1LL * cur * (n - i)) % mod;
        cur = (1LL * cur * power(mod + 1 - i , mod - 2)) % mod;
    }
    for(int i = 1 ; i <= k + 2 ; ++i){
        ans = (ans + 1LL * cur * val[i]) % mod;
        cur = (1LL * cur * (n - i)) % mod;
        cur = (1LL * cur * (i - k - 2 + mod)) % mod;
        cur = (1LL * cur * power((1LL * (n - i - 1) * i) % mod , mod - 2)) % mod;
    }
    printf("%d\n" , ans);
}