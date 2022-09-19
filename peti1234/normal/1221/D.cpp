#include <bits/stdc++.h>

using namespace std;
const int c=300002;
long long dp[c][3], a[c], b[c], sok=1e18;
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            long long x, y;
            cin >> x >> y;
            a[i]=x, b[i]=y;
            dp[i][0]=sok, dp[i][1]=sok, dp[i][2]=sok;
            for (int j=0; j<=2; j++) {
                for (int k=0; k<=2; k++) {
                    if (a[i-1]+j!=x+k) {
                        dp[i][k]=min(dp[i][k], dp[i-1][j]+k*y);
                    }
                }
            }
        }
        long long mini=min(dp[n][0], dp[n][1]);
        mini=min(mini, dp[n][2]);
        cout << mini << "\n";
    }
    return 0;
}