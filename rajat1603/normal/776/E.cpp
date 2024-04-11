#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int SZ = 1e5 + 5;
const int mod = 1000000007;
bool p[N];
int primes[SZ];
int sz;
void pre(){
    memset(p , 0 , sizeof(p));
    sz = 0;
    for(int i = 2 ; i * i < N ; ++i){
        if(!p[i]){
            for(int j = i * i ; j < N ; j += i){
                p[j] = 1;
            }
        }
    }
    for(int i = 2 ; i < N ; ++i){
        if(!p[i]){
            primes[++sz] = i;
        }
    }
}
long long n , k;
long long phi(long long n){
    long long res = n;
    for(int i = 1 ; i <= sz ; ++i){
        long long p = primes[i];
        if(p * p > n){
            break;
        }
        if(n % p == 0){
            while(n % p == 0){
                n /= p;
            }
            res /= p;
            res *= p - 1;
        }
    }
    if(n > 1){
        res /= n;
        res *= n - 1;
    }
    return res;
}
long long solve(long long n , long long k){
    if(k == 1 || n == 1){
        return phi(n);
    }
    return solve(phi(n) , k - 1);
}
int main(){
    pre();
    scanf("%lld %lld" , &n , &k);
    k = k + 1 >> 1;
    printf("%lld\n" , solve(n , k) % mod);
}