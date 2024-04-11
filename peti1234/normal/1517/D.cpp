#include <bits/stdc++.h>

using namespace std;
const int c=502, sok=1e8, f=12;
int n, m, hh, h, el[c][c][4], dp[c][c][f];
bool v[c][c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> hh;
    h=hh/2;
    for (int i=0; i<=n+1; i++) {
        for (int j=0; j<=m+1; j++) {
            for (int k=0; k<4; k++) {
                //el[i][j][k]=sok;
            }
            for (int k=0; k<f; k++) {
                dp[i][j][k]=sok;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<m; j++) {
            int x;
            cin >> x;
            el[i][j][1]=x, el[i][j+1][3]=x;
        }
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<=m; j++) {
            int x;
            cin >> x;
            el[i][j][2]=x, el[i+1][j][0]=x;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j][0]=0;
        }
    }
    for (int k=1; k<=h; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                dp[i][j][k]=min({el[i][j][0]+dp[i-1][j][k-1], el[i][j][1]+dp[i][j+1][k-1], el[i][j][2]+dp[i+1][j][k-1], el[i][j][3]+dp[i][j-1][k-1]});
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j][h]*=2;
            if (hh%2) {
                dp[i][j][h]=-1;
            }
            cout << dp[i][j][h] << " ";
        }
        cout << "\n";
    }
    return 0;
}