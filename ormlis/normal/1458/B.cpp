#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;

using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e9;
const int maxN = 100 + 5;
const int md2 = 998244353;
const int md = 999999001;

// min(sum(a[j]), (B + sum(b[j])) / 2)
int dp[maxN][maxN][maxN*maxN];
void solve() {
    int n; cin >> n;
    int B = 0;
    range(i, maxN) range(j, maxN) range(e, maxN * maxN) dp[i][j][e] = -INFi;
    dp[0][0][0] = 0;
    range(i, n) {
        int a, b; cin >> a >> b;
        B += b;
        range(k, n + 1) {
            range(suma, 100 * 100 + 5) {
                dp[i + 1][k][suma] = dp[i][k][suma];
                if (k > 0 && suma >= a && dp[i][k - 1][suma - a] != -INFi) {
                    dp[i + 1][k][suma] = max(dp[i + 1][k][suma], dp[i][k - 1][suma - a] + b);
                }
            }
        }
    }
    for(int k = 1; k <= n; ++k) {
        long double ans = 0;
        range(suma, 100 * 100 + 5) {
            ans = max(ans, min((long double)suma, (long double)(B + dp[n][k][suma]) / 2));
        }
        cout << ans << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}