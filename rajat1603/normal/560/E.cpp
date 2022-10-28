#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int K = 2005;
const int mod = 1e9 + 7;
int dp[K];
pair < int , int > arr[K];
int fact[N];
int ifact[N];
int n , m , k;
void pre(){
    fact[0] = 1;
    for(int i = 1 ; i < N ; ++i){
        fact[i] = (1LL * fact[i - 1] * i) % mod;
    }
    ifact[N - 1] = 1;
    int expo = mod - 2;
    int base = fact[N - 1];
    while(expo){
        if(expo & 1){
            ifact[N - 1] = (1LL * ifact[N - 1] * base) % mod;
        }
        base = (1LL * base * base) % mod;
        expo >>= 1;
    }
    for(int i = N - 2 ; i >= 0 ; --i){
        ifact[i] = (1LL * ifact[i + 1] * (i + 1)) % mod;
    }
}
int C(int n , int r){
    return (1LL * ((1LL * fact[n] * ifact[r]) % mod) * ifact[n - r]) % mod;
}
int ways(int x1 , int y1 , int x2 , int y2){
    return C(x2 - x1 + y2 - y1 , y2 - y1);
}
int main(){
    cin >> n >> m >> k;
    for(int i = 1 ; i <= k ; ++i){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr + 1 , arr + 1 + k);
    arr[k + 1].first = n;
    arr[k + 1].second = m;
    ++k;
    pre();
    for(int i = 1 ; i <= k ; ++i){
        dp[i] = ways(1 , 1 , arr[i].first , arr[i].second);
        for(int j = 1 ; j < i ; ++j){
            if(arr[j].second <= arr[i].second){
                dp[i] -= (1LL * dp[j] * ways(arr[j].first , arr[j].second , arr[i].first , arr[i].second)) % mod;
                if(dp[i] < 0){
                    dp[i] += mod;
                }
            }
        }
    }
    printf("%d\n" , dp[k]);
}