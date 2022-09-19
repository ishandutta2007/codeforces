#include <bits/stdc++.h>

using namespace std;
const int c=2005;
int w, n, dp[c][c], db[c][c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> dp[i][0];
            db[dp[i][0]][0]++;
        }
        for (int j=1; j<=n; j++) {
            for (int i=1; i<=n; i++) {
                dp[i][j]=db[dp[i][j-1]][j-1];
                db[dp[i][j]][j]++;
            }
        }
        int q;
        cin >> q;
        while (q--) {
            int a, b;
            cin >> a >> b;
            b=min(b, n);
            cout << dp[a][b] << "\n";
        }
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                db[i][j]=0, dp[i][j]=0;
            }
        }
    }
    return 0;
}