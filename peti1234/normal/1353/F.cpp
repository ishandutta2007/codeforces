#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const long long c=102, sok=4e18;
int w;
ll t[c][c], dp[c][c], n, m, mini, x;
bool jo(int a, int b) {
    return (a<=n && b<=m && dp[a][b]<sok && dp[a][b]>=0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m, mini=sok;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin >> t[i][j], t[i][j]-=i+j;
        /*for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) cout << t[i][j] << " ";
            cout << "\n";
        }*/
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
            x=t[i][j];
            for (int i=n; i>=1; i--) for (int j=m; j>=1; j--) {
                dp[i][j]=sok;
                if (t[n][m]>=x) dp[n][m]=t[n][m]-x;
                if (t[i][j]>=x) {
                    if (jo(i+1, j)) dp[i][j]=min(dp[i][j], dp[i+1][j]+t[i][j]-x);
                    if (jo(i, j+1)) dp[i][j]=min(dp[i][j], dp[i][j+1]+t[i][j]-x);
                }
            }
            //cout << x << " " << mini << endl;
            if (jo(1, 1)) mini=min(mini, dp[1][1]);
        }
        cout << mini << "\n";
    }
    return 0;
}
/*
1
5 5
2 5 4 8 3
9 10 11 5 1
12 8 4 2 5
2 2 5 4 1
6 8 2 4 2
*/