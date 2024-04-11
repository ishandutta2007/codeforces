#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int w, n, k, z, t[c], dp[c][6], maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k >> z;
        for (int i=1; i<=n; i++) cin >> t[i], dp[i][0]=dp[i-1][0]+t[i];
        for (int i=1; i<=n; i++) for (int j=1; j<=z; j++) dp[i][j]=0;
        maxi=dp[k+1][0];
        for (int j=1; j<=z; j++) for (int i=1; i<=k+1-2*j; i++) dp[i][j]=t[i]+max(dp[i-1][j], dp[i+1][j-1]), maxi=max(maxi, dp[i][j]);
        cout << maxi << "\n";
    }
    return 0;
}