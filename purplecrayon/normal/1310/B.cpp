#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 18, MOD = 1e9+7;

int n, m, dp[MAXN][1<<MAXN][2][2];

void solve(){
    cin >> n >> m;
    for (int i = 0; i <= n; i++) for (int j = 0; j < (1<<(n+1)); j++)
        for (int k : {0, 1}) for (int l : {0, 1})
            dp[i][j][k][l] = (i ? -MOD : 0);

    for (int i = 0; i < m; i++) {
        int c; cin >> c, --c;
        dp[0][c][1][0] = 1;
    }
    for (int i = 0; i < (1<<(n-1)); i++) {
        int a = dp[0][2*i][1][0], b = dp[0][2*i+1][1][0];
        for (int rep : {0, 1}) {
            dp[1][i][a][b] = a|b;
            swap(a, b);
        }
    }

    for (int i = 2; i <= n; i++) for (int j = 0; j < (1<<(n-i)); j++) for (int v1 : {0, 1}) for (int v3 : {0, 1}) for (int v2 : {0, 1}) for (int v4 : {0, 1}) {
        int a = v1 | v2, b = v3 | v4, x1 = dp[i-1][2*j+1][v2][v4]+dp[i-1][2*j][v1][v3];
        dp[i][j][a][b] = max(dp[i][j][a][b], a+2*b+x1);
        if (a) {
            dp[i][j][v1&v2][1] = max(dp[i][j][v1&v2][1], x1+b+2);
        }
    }

    int ans=0;
    for (int v1 : {0, 1}) for (int v2 : {0, 1}) {
        ans = max(ans, (v1|v2) + dp[n][0][v1][v2]);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}