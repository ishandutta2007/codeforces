#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
int n , k , d;
int dp[101][2] = {0};
int main(){
    cin >> n >> k >> d;
    dp[0][1] = 1;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 0 ; j < 2 ; ++j){
            for(int l = 1 ; l <= min(i , k) ; ++l){
                dp[i][j] += dp[i - l][j | (l >= d)];
                if(dp[i][j] >= mod){
                    dp[i][j] -= mod;
                }
            }
        }
    }
    cout << dp[n][0];
}