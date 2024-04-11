#include <bits/stdc++.h>

using namespace std;
const int c=4002, f=802;
int n, k, t[c][c], kom[c][c], sum[c][c], dp[c][f];
void solve(int x, int l, int r, int kezd, int veg) {
    if (l>r) return;
    int mid=(l+r)/2, pos=-1, ert=1e9;
    for (int i=kezd; i<=veg; i++) {
        int nert=dp[i-1][x-1]+sum[i][mid];
        if (nert<ert) {
            pos=i, ert=nert;
        }
    }
    dp[mid][x]=ert;
    solve(x, l, mid-1, kezd, pos);
    solve(x, mid+1, r, pos, veg);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            char c; cin >> c;
            t[i][j]=c-'0';
            if (i<j) t[i][j]=0;
            kom[i][j]=kom[i][j-1]+kom[i-1][j]-kom[i-1][j-1]+t[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j++) {
            sum[i][j]=kom[j][j]-kom[i-1][j]-kom[j][i-1]+kom[i-1][i-1];
        }
    }
    for (int i=1; i<=n; i++) {
        dp[i][1]=sum[1][i];
    }
    for (int i=2; i<=k; i++) {
        solve(i, 1, n, 1, n);
    }
    cout << dp[n][k] << "\n";
    return 0;
}