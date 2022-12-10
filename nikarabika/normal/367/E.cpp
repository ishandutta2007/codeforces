#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    const LL Mod = 1000 * 1000 * 1000 + 7;
    int n, m, x;
    cin >> n >> m >> x;
    if (n > m)
        return cout << 0 << endl, 0;
    LL dp[2][n+1][n+1];
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    int cur = 1, prv = 0;
    for (int i = 1; i <= m; i++, swap(cur, prv)) {
        memset(dp[cur], 0, sizeof dp[cur]);
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= j; k++) {
                if (j)
                    dp[cur][j][k] += dp[prv][j - 1][k];
                if (j and k)
                    dp[cur][j][k] += dp[prv][j - 1][k - 1];
                if (i != x) {
                    dp[cur][j][k] += dp[prv][j][k];
                    if (k)
                        dp[cur][j][k] += dp[prv][j][k - 1];
                }
                dp[cur][j][k] %= Mod;
            }
    }
    LL ans = dp[prv][n][n];
    for (int i = 1; i <= n; i++)
        ans = ans * i % Mod;
    cout << ans << endl;
    return 0;
}