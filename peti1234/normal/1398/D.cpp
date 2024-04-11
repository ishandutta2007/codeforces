#include <bits/stdc++.h>

using namespace std;
#define rep(a, b) for (int a=1; a<=b; a++)
const int c=202;
int dp[c][c][c], r[c], g[c], b[c], x, y, z, maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> x >> y >> z;
    rep(i, x) cin >> r[i], r[i]*=-1;
    rep(i, y) cin >> g[i], g[i]*=-1;
    rep(i, z) cin >> b[i], b[i]*=-1;
    sort(r+1, r+x+1), sort(g+1, g+y+1), sort(b+1, b+z+1);
    rep(i, min(x, y)) dp[i][i][0]=dp[i-1][i-1][0]+r[i]*g[i], maxi=max(maxi, dp[i][i][0]);
    rep(i, min(x, z)) dp[i][0][i]=dp[i-1][0][i-1]+r[i]*b[i], maxi=max(maxi, dp[i][0][i]);
    rep(i, min(y, z)) dp[0][i][i]=dp[0][i-1][i-1]+g[i]*b[i], maxi=max(maxi, dp[0][i][i]);
    rep(i, x) rep(j, y) rep(k, z) dp[i][j][k]=max({dp[i-1][j-1][k]+r[i]*g[j], dp[i-1][j][k-1]+r[i]*b[k], dp[i][j-1][k-1]+g[j]*b[k]}), maxi=max(maxi, dp[i][j][k]);
    cout << maxi << "\n";
    return 0;
}