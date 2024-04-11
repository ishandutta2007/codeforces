#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i=1; i<=n; i++)
const int c=4002, k=-1e9;
int n, m, l[c], s[c], f[c], dp[c][c], maxi, x, p;
void upd(int a, int b) {
    if (a>m) return;
    rep(i, b+1) x=i-1, dp[a][x]=max(dp[a][x], f[a]*x+max(dp[a-1][2*x], dp[a-1][2*x+1]));
    upd(a+1, b/2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m, m=n+m;
    rep(i, n) cin >> l[n+1-i];
    rep(i, n) cin >> s[n+1-i];
    rep(i, m) cin >> f[i];
    rep(i, m) rep(j, m+1) dp[i][j]=k;
    rep(i, n) {
        x=l[i], p=f[x]-s[i];
        for (int j=m; j>0; j--) dp[x][j]=max(dp[x][j], dp[x][j-1]+p);
        upd(x+1, m/2);
    }
    rep(i, m) maxi=max(maxi, dp[i][1]);
    cout << maxi << "\n";
    return 0;
}