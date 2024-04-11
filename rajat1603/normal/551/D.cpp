#include "bits/stdc++.h"
using namespace std;
long long n , k;
int l , mod;
void fib(long long n, long long &x, long long &y){
    if(n == 1){
        x = y = 1LL;
        return ;
    }
    if(n & 1){
        fib(n - 1 , y , x);
        y += x;
        if(y >= mod){
            y -= mod;
        }
    }
    else{
        long long a, b;
        fib(n >> 1 , a , b);
        y = (a * a + b * b) % mod;
        x = (a * b + a * (b - a + mod)) % mod;
    }
}
long long power(){
    long long res = 1;
    long long base = 2;
    long long expo = n;
    while(expo){
        if(expo & 1){
            res *= base;
            res = (res >= mod) ? res % mod : res;
        }
        base *= base;
        base = (base >= mod) ? base % mod : base;
        expo >>= 1;
    }
    return res;
}
int main(){
    cin >> n >> k >> l >> mod;
    if(l < 63 &&  (1LL << l) <= k){
        cout << 0;
        return 0;
    }
    long long fibo , pow2;
    fib(n + 2 , fibo , pow2);
    pow2 = power();
    long long ans = 1 % mod;
    for(int i = 0 ; i < l ; ++i){
        if(k & (1LL << i)){
            ans *= pow2 - fibo + mod;
            ans = (ans >= mod) ? ans % mod : ans;
        }
        else{
            ans *= fibo;
            ans = (ans >= mod) ? ans % mod : ans;
        }
    }
    cout << ans;
}