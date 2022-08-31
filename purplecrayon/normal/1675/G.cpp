#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2.5e2+10, MOD = 1e9+7;
const int INF = MOD;

int n, m;
int a[N], ps[N], dp[N][N][N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) ps[i] = a[i] + (i ? ps[i-1] : 0);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int k = 0; k < N; k++)
        dp[i][j][k] = INF;

    auto DP = [&](int i, int j, int k) {
        if (i == -1) {
            if (j == 0 && k == m) return 0;
            return INF;
        }
        return dp[i][j][k];
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            int mn = INF;
            for (int k = m; k >= 0; k--) {
                mn = min(mn, DP(i-1, j, k));
                if (j + k <= m) {
                    dp[i][j + k][k] = min(dp[i][j + k][k], mn + abs(ps[i] - (j + k)));
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= m; i++) ans = min(ans, DP(n-1, m, i));
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}