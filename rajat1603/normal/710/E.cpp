#include "bits/stdc++.h"
using namespace std;
const int N = 2e7 + 7;
const long long inf = 1e18;
int n , x , y;
long long dp[N];
int main(){
    scanf("%d %d %d" , &n , &x , &y);
    dp[0] = 0;
    dp[1] = x;
    for(int i = 2 ; i <= n + n ; ++i){
        dp[i] = inf;
    }
    for(int i = 2 ; i <= n ; i += i){
        for(int j = i ; j <= i + i ; j += 2){
            dp[j] = min(dp[j] , dp[j >> 1] + y);
        }
        for(int j = i ; j <= i + i ; ++j){
            dp[j] = min(dp[j] , dp[j - 1] + x);
        }
        for(int j = i + i ; j >= i ; --j){
            dp[j] = min(dp[j] , dp[j + 1] + x);
        }
    }
    printf("%lld\n" , dp[n]);
}