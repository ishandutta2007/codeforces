#include <bits/stdc++.h>

using namespace std;
const int c=20001, m=10000;
int dp[1005][c], n, x, ans, mod=1e9+7;
int main()
{
    dp[0][m]=1;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        for (int j=0; j<=2*m; j++) {
            if (dp[i-1][j]) {
                dp[i][j-x]=(dp[i][j-x]+dp[i-1][j])%mod;
                dp[i][j+x]=(dp[i][j+x]+dp[i-1][j])%mod;
            }
        }
        ans=(ans+dp[i][m]++)%mod;
    }
    cout << ans << "\n";
    return 0;
}