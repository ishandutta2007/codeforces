#include <bits/stdc++.h>

using namespace std;
const int c=5005;
int n, t[c], dp[c][c], k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    t[0]=-10;
    for (int i=1; i<=n; i++) {
        int pos=i;
        while (t[i]-t[pos]<=5) pos--;
        for (int j=1; j<=k; j++) {
            dp[i][j]=max(dp[i-1][j], dp[pos][j-1]+i-pos);
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}