#include <bits/stdc++.h>

using namespace std;
const int c=1005, sok=1e6;
int n, t[c][c], dp[c][c][2], xx, yy;
bool s[c][c][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> t[i][j];
        }
    }
    for (int p=0; p<2; p++) {
        int val=(p==0 ? 2 : 5);
        for (int i=2; i<=n; i++) {
            dp[i][0][p]=dp[0][i][p]=sok;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                s[i][j][p]=(dp[i][j-1][p]<dp[i-1][j][p]);
                dp[i][j][p]=min(dp[i][j-1][p], dp[i-1][j][p]);
                int x=t[i][j];
                if (x==0) {
                    dp[i][j][p]+=2;
                    xx=i, yy=j;
                    continue;
                }
                while (x%val==0) {
                    x/=val;
                    dp[i][j][p]++;
                }
            }
        }
    }
    int p=(dp[n][n][0]>dp[n][n][1]);
    if (xx && dp[n][n][p]>1) {
        cout << 1 << "\n";
        int x=1, y=1;
        while (x<xx) {
            cout << "D";
            x++;
        }
        while (y<n) {
            cout << "R";
            y++;
        }
        while (x<n) {
            cout << "D";
            x++;
        }
        return 0;
    }
    cout << dp[n][n][p] << "\n";
    string ans;
    int x=n, y=n;
    while (x+y>2) {
        if (s[x][y][p]) {
            ans+="R";
            y--;
        } else {
            ans+="D";
            x--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return 0;
}