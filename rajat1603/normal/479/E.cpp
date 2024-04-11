#include "bits/stdc++.h"
using namespace std;
const int N = 5005;
const int mod = 1e9 + 7;
int n , a , b , k;
int dp[N][N] = {0};
int sum[N][N] = {0};
int main(){
    cin >> n >> a >> b >> k;
    for(int i = 0 ; i <= k ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            if(!i){
                dp[i][j] = 1;
            }
            else{
                int sz = abs(j - b);
                dp[i][j] += sum[i - 1][min(n , j + sz - 1)] - sum[i - 1][j];
                if(dp[i][j] < 0){
                    dp[i][j] += mod;
                }
                dp[i][j] += sum[i - 1][j - 1] - sum[i - 1][max(0 , j - sz)];
                if(dp[i][j] >= mod){
                    dp[i][j] -= mod;
                }
                else if(dp[i][j] < 0){
                    dp[i][j] += mod;
                }
            }
        }
        sum[i][0] = 0;
        for(int j = 1 ; j <= n ; ++j){
            sum[i][j] = sum[i][j - 1] + dp[i][j];
            if(sum[i][j] >= mod){
                sum[i][j] -= mod;
            }
        }
    }
    cout << dp[k][a];
}