#include <bits/stdc++.h>

using namespace std;
const int c=3002;
int w, n, t[c], dp[c][c];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (i>1) for (int j=1; j<=n; j++) dp[i][j]=c;
        }
        for (int i=2; i<=n; i++) {
            int cnt=0;
            for (int j=i-1; j; j--) {
                int x=j+t[j];
                if (x>=i) {
                    dp[i][x]=min(dp[i][x], dp[j][i-1]+cnt);
                    cnt++;
                }
            }
            for (int j=i; j<=n; j++) {
                dp[i][j]=min(dp[i][j], dp[i][j-1]);
            }
        }
        cout << dp[n][n] << "\n";
    }
    return 0;
}