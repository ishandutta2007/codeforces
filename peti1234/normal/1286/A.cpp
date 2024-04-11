#include <bits/stdc++.h>

using namespace std;
const int c=102;
int n, t[c], dp[c][c][2], x;
int main()
{
    cin >> n, x=n-n/2;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) dp[i][j][0]=-c, dp[i][j][1]=-c;
    dp[0][0][0]=-1, dp[0][0][1]=-1;
    for (int i=1; i<=n; i++) for (int j=0; j<=x; j++) {
        if (t[i]) {
            if (t[i]%2) {
                if (!j) dp[i][j][0]=-c, dp[i][j][1]=-c;
                else dp[i][j][1]=max(dp[i-1][j-1][0], dp[i-1][j-1][1]+1), dp[i][j][0]=-c;
            } else dp[i][j][0]=max(dp[i-1][j][0]+1, dp[i-1][j][1]), dp[i][j][1]=-c;
        } else {
            dp[i][j][0]=max(dp[i-1][j][0]+1, dp[i-1][j][1]);
            if (!j) dp[i][j][1]=-c;
            else dp[i][j][1]=max(dp[i-1][j-1][0], dp[i-1][j-1][1]+1);
        }
    }
    cout << n-1-max(dp[n][x][0], dp[n][x][1]);
    return 0;
}