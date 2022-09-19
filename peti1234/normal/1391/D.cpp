#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
int n, m, dp[c][4];
bool v[4][c];
int main()
{
    cin >> n >> m;
    if (n>3) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i=0; i<n; i++) for (int j=1; j<=m; j++) {char c; cin >> c; if (c=='1') v[i][j]=1;}
    if (n==1) cout << 0;
    else if (n==2) {
        for (int i=1; i<=m; i++) {
            dp[i][0]=dp[i-1][1], dp[i][1]=dp[i-1][0];
            bool db=(v[0][i]+v[1][i])%2;
            dp[i][!db]++;
        }
        cout << min(dp[m][0], dp[m][1]);
    } else {
        for (int i=1; i<=m; i++) {
            for (int j=0; j<4; j++) dp[i][j]=dp[i-1][3-j]+1;
            bool a=(v[0][i]+v[1][i])%2, b=(v[1][i]+v[2][i])%2;
            dp[i][2*a+b]--;
        }
        cout << min({dp[m][0], dp[m][1], dp[m][2], dp[m][3]});
    }
    return 0;
}