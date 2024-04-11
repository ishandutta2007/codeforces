#include <bits/stdc++.h>

using namespace std;
long long n, x, y, dp[5005][2][2], sok=1e16;
string a, b;
void solve() {
    cin >> n >> x >> y >> a >> b;
    x=min(x, 2*y);
    //cout << "valasz............ ";
    if (y<=x) {
        int si=0;
        vector<int> sz;
        for (int i=0; i<n; i++) {
            if (a[i]!=b[i]) sz.push_back(i);
        }
        si=sz.size();
        if (si%2) {
            cout << -1 << "\n";
            return;
        }
        if (si==2 && sz[0]+1==sz[1]) {
            cout << x << "\n";
        } else {
            cout << si/2*y << "\n";
        }
        return;
    }
    for (int i=0; i<=n; i++) for (int j=0; j<2; j++) for (int k=0; k<2; k++) dp[i][j][k]=sok;
    dp[0][0][0]=0;
    for (int i=1; i<=n; i++) {

        bool p=(a[i-1]!=b[i-1]);

        dp[i][0][0]=dp[i-1][0][p];
        dp[i][1][0]=dp[i-1][1][p];

        dp[i][0][1]=dp[i-1][0][1-p]+x;
        dp[i][1][1]=dp[i-1][1][1-p]+x;

        dp[i][0][0]=min(dp[i][0][0], dp[i-1][1][1-p]);
        dp[i][1][0]=min(dp[i][1][0], dp[i-1][0][1-p]+y);

    }
    long long ans=dp[n][0][0];
    cout << (ans>=sok ? -1 : ans) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
7 8 3
0111001
0100001
*/