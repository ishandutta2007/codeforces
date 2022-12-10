#include <bits/stdc++.h>

using namespace std;

double dp[2001][2001];
double p;

void DP(int n, int t){
    if(n == 0){
        dp[n][t] = 0;
        return;
    }
    if(t == 1){
        dp[n][t] = p;
        return;
    }
    if(dp[n][t - 1] == -1)
        DP(n, t - 1);
    if(dp[n - 1][t - 1] == -1)
        DP(n - 1, t - 1);
    dp[n][t] = p * (1 + dp[n - 1][t - 1]) + (1.0 - p) * dp[n][t - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n >> p >> t;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= t; j++)
            dp[i][j] = -1;
    DP(n, t);
    cout.precision(6);
    cout << fixed << dp[n][t] << endl;
}