#include "bits/stdc++.h"
using namespace std;
const int N = 2e6 + 6;
const int mod = 1e9 + 7;
int fact[N];
int ifact[N];
int spf[N];
int pw2[N];
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
void pre(){
    fact[0] = 1;
    for(int i = 1 ; i < N ; ++i){
        fact[i] = (1LL * fact[i - 1] * i) % mod;
    }
    ifact[N - 1] = power(fact[N - 1] , mod - 2);
    for(int i = N - 2 ; i >= 0 ; --i){
        ifact[i] = (1LL * ifact[i + 1] * (i + 1)) % mod;
    }
    spf[1] = 1;
    for(int i = 2 ; i < N ; ++i){
        if(!spf[i]){
            for(int j = i ; j < N ; j += i){
                if(!spf[j]){
                    spf[j] = i;
                }
            }
        }
    }
    pw2[0] = 1;
    for(int i = 1 ; i < N ; ++i){
        pw2[i] = (pw2[i - 1] + pw2[i - 1]) % mod;
    }
}
int ncr(int n , int r){
    return (((1LL * fact[n] * ifact[r]) % mod) * ifact[n - r]) % mod;
}
int t;
int r , n;
int main(){
    pre();
    scanf("%d" , &t);
    while(t--){
        scanf("%d %d" , &r , &n);
        int ans = 1;
        int cnt = 0;
        int lst = spf[n];
        while(n > 1){
            if(spf[n] == lst){
                ++cnt;
            }
            else{
                int tmp = 0;
                tmp += 2 * ncr(r + cnt - 1 , r);
                tmp %= mod;
                tmp += ncr(r + cnt - 1 , cnt);
                tmp %= mod;
                ans = (1LL * ans * tmp) % mod;
                lst = spf[n];
                cnt = 1;
            }
            n /= spf[n];
        }
        if(cnt){
            int tmp = 0;
            tmp += 2 * ncr(r + cnt - 1 , r);
            tmp %= mod;
            tmp += ncr(r + cnt - 1 , cnt);
            tmp %= mod;
            ans = (1LL * ans * tmp) % mod;
        }
        printf("%d\n" , ans);
    }
}