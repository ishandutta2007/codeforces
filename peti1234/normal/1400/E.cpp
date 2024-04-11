#include <bits/stdc++.h>

using namespace std;
const int c=5002;
int dp[c][c], t[c], n;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i], dp[0][i]=i;
    for (int i=1; i<=n; i++) {
        t[i]=min(t[i], n);
        for (int j=0; j<=t[i]; j++) dp[i][j]=min(dp[i-1][j]+1, dp[i-1][t[i]]);
        for (int j=t[i]+1; j<=n; j++) dp[i][j]=dp[i][t[i]]+j-t[i];
    }
    cout << dp[n][0] << "\n";
    return 0;
}