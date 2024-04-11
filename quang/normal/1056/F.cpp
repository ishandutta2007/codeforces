#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int M = N * 10;
typedef long double ld;
const ld INF = 1e18;

int n;
ld c, t;
pair<int, int> a[N];
ld dp[2][N][M];
ld p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p[0] = 1.;
    for (int i = 1; i < N; i++) {
        p[i] = p[i - 1] * 10. / 9.;
    }
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cin >> c >> t;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a + 1, a + n + 1, greater<pair<int, int> >());
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n * 10; j++) {
                dp[0][i][j] = dp[1][i][j] = INF;
            }
        }
        dp[0][0][0] = 0.;
        int cur = 1;
        for (int i = 1; i <= n; i++, cur ^= 1) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= n * 10; k++) {
                    dp[cur][j][k] = dp[cur ^ 1][j][k];
                    if (j > 0 && k >= a[i].second) {
                        dp[cur][j][k] = min(dp[cur][j][k], dp[cur ^ 1][j - 1][k - a[i].second] + p[j] * a[i].first);
                    }
                }
            }
        }
        cur ^= 1;
        int res = 0;
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n * 10; k++) {
                ld A = dp[cur][j][k];
                ld x = max((sqrt(A * c) - 1.) / c, (ld)0.);
                ld tot = (ld)10. * j + x + A / (c * x + 1.);
                if (tot <= t) {
                    res = max(res, k);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}