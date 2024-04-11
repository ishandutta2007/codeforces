#include <bits/stdc++.h>

using namespace std;
int n, m, dp[50005][6];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int x;
            cin >> x;
            dp[i][j]=max(dp[i-1][j], dp[i][j-1])+x;
        }
    }
    for (int i=1; i<=n; i++) {
        cout << dp[i][m] << " ";
    }
    cout << "\n";
    return 0;
}