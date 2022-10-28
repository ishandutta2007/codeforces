#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int t;
int n , f;
int fact[N];
int ifact[N];
vector < int > v[N];
int nu[N];
bool pr[N];
void pre(){
    fact[0] = 1;
    for(int i = 1 ; i < N ; ++i){
        fact[i] = (1LL * fact[i - 1] * i) % mod;
    }
    ifact[N - 1] = 931791584;
    for(int i = N - 2 ; i >= 0 ; --i){
        ifact[i] = (1LL * ifact[i + 1] * (i + 1LL)) % mod;
    }
    for(int i = 0 ; i < N ; ++i){
        nu[i] = 1;
    }
    for(int i = 2 ; i < N ; ++i){
        if(!pr[i]){
            if(1LL * i * i < N){
                for(int j = i * i ; j < N ; j += i){
                    pr[j] = 1;
                }
                for(int j = i * i ; j < N ; j += i * i){
                    nu[j] = 0;
                }
            }
            for(int j = i ; j < N ; j += i){
                nu[j] *= -1;
            }
        }
    }
    for(int i = 1 ; i < N ; ++i){
        if(nu[i]){
            for(int j = i ; j < N ; j += i){
                v[j].emplace_back(i);
            }
        }
    }
}
inline int ncr(int n , int r){
    return (n >= r) ? ((1LL * fact[n] * ifact[r]) % mod) * ifact[n - r] % mod : 0;
}
int main(){
    pre();
    scanf("%d" , &t);
    while(t--){
        scanf("%d %d" , &n , &f);
        long long ans = 0;
        for(int g : v[n]){
            ans += ncr(n / g - 1 , f - 1) * nu[g];
        }
        printf("%lld\n" , ((ans % mod) + mod) % mod);
    }
}