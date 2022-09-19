#include <bits/stdc++.h>

using namespace std;
const int c=402;
int w, n, dp[c][c], t[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=1; i<=n; i++) for (int j=1; j<c; j++) dp[i][j]=c*c;
        sort(t+1, t+n+1);
        for (int i=1; i<=n; i++) {
            int mini=dp[i-1][i-1];
            for (int j=i; j<c; j++) {
                dp[i][j]=min(dp[i][j], mini+abs(t[i]-j));
                mini=min(mini, dp[i-1][j]);
            }
        }
        int ans=c*c;
        for (int i=1; i<c; i++) ans=min(ans, dp[n][i]);
        cout << ans << "\n";
    }
    return 0;
}