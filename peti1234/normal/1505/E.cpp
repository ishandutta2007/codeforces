#include <bits/stdc++.h>

using namespace std;
int n, m, t[10][10], dp[10][10];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            if (c=='*') {
                t[i][j]=1;
            }
        }
    }
    for (int i=1; i<=n+1; i++) {
        for (int j=1; j<=m+1; j++) {
            dp[i][j]=100;
        }
    }
    dp[n+1][m]=0;
    for (int i=n; i>=1; i--) {
        for (int j=m; j>=1; j--) {
            if (t[i+1][j]>t[i][j+1]) {
                dp[i][j]=dp[i+1][j];
            }
            if (t[i][j+1]>t[i+1][j]) {
                dp[i][j]=dp[i][j+1];
            }
            if (t[i+1][j]==t[i][j+1]) {
                dp[i][j]=min(dp[i][j+1], dp[i+1][j]);
            }
            dp[i][j]+=t[i][j];
        }
    }
    cout << dp[1][1] << "\n";
    return 0;
}