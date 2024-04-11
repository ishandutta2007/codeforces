#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int K = 5e3 + 3;
int n , k;
int arr[N];
int dp[K][K];
long long solve(int big , int small , int pos){
    if(pos > n){
        return 0;
    }
    if(dp[big][small] != -1){
        return dp[big][small];
    }
    long long res = 1LL << 50; 
    if(big){
        res = solve(big - 1 , small , pos + (n / k) + 1) + arr[pos + (n / k)] - arr[pos];
    }
    if(small){
        res = min(res , solve(big , small - 1 , pos + (n / k)) + arr[pos + (n / k) - 1] - arr[pos]);
    }
    return dp[big][small] = res;
}
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    sort(arr + 1 , arr + 1 + n);
    memset(dp , -1 , sizeof(dp));
    printf("%lld\n" , solve(n % k , k - (n % k) , 1));
}