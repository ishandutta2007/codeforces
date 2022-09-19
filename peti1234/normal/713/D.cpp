#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int n, m, q, t[c][c], dp[c][c][10][10], ert[1001];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i=2; i<=max(n, m); i++) ert[i]=ert[i/2]+1;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin >> t[i][j];
    for (int i=n; i>=1; i--) for (int j=m; j>=1; j--) dp[i][j][0][0]=(min({dp[i+1][j][0][0], dp[i+1][j+1][0][0], dp[i][j+1][0][0]})+1)*t[i][j];
    for (int k=1; k<10; k++) for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        dp[i][j][k][0]=dp[i][j][k-1][0];
        int x=min(n, i+(1<<(k-1)));
        if (x<=n) dp[i][j][k][0]=max(dp[i][j][k][0], dp[x][j][k-1][0]);
    }
    for (int p=0; p<10; p++) for (int k=1; k<10; k++) for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        dp[i][j][p][k]=dp[i][j][p][k-1];
        int y=min(m, j+(1<<(k-1)));
        if (y<=m) dp[i][j][p][k]=max(dp[i][j][p][k], dp[i][y][p][k-1]);
    }
    cin >> q;
    for (int i=1; i<=q; i++) {
        int a, b, c, d, l=0, h=n+1;
        cin >> a >> b >> c >> d;
        while(h-l>1) {
            int p=(h+l)/2, cc=c-p+1, dd=d-p+1;
            if (a>cc || b>dd) h=p;
            else {
                int x=ert[cc-a], y=ert[dd-b], e=cc-(1<<x)+1, f=dd-(1<<y)+1;
                int maxi=max({dp[a][b][x][y], dp[e][b][x][y], dp[a][f][x][y], dp[e][f][x][y]});
                if (maxi>=p) l=p;
                else h=p;
            }
        }
        cout << l << "\n";
    }
    return 0;
}