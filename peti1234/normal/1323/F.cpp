#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i=1; i<=n; i++)
const int c=4002, k=-1e9;
int n, m, l[c], s[c], f[c], dp[c][c], maxi;
void upd(int a, int b) {
    //cout << "upd " << a << " " << b << "\n";
    if (a>m) return;
    rep(i, b+1) {
        int x=i-1;
        dp[a][x]=max(dp[a][x], f[a]*x+max(dp[a-1][2*x], dp[a-1][2*x+1]));

        //cout << "upd " << a << " " << x << " " << dp[a][x] << endl;
    }
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
        int x=l[i], p=f[x]-s[i];
        //cout << "alap " << x << " " << p << endl;
        for (int j=m; j>0; j--) {
            dp[x][j]=max(dp[x][j], dp[x][j-1]+p);
            //cout << x << " " << j << " " << dp[x][j] << endl;
        }
        upd(x+1, m/2);
    }
    rep(i, m) maxi=max(maxi, dp[i][1]);
    cout << maxi << "\n";
    return 0;
}
/*
7 5
4 3 2 3 2 1 1
6 8 9 1 2 0 5
14 6 0 14 -12 -2 -13 10 -14 -3 10 -9
*/