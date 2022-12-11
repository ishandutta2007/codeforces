//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll mod) {
    return (ull)rng() % mod;
}

const int inf = (int) 1e7;
const int maxn = (int) 1e5 + 42;

int dp[maxn][2][2];

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = inf;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int prev = 0; prev < 2; ++prev) {
            for (int last = 0; last < 2; ++last) {
                for (int next = 0; next < 2; ++next) {
                    if (!next && !last && (i > 0 && s[i] == s[i - 1])) {
                        continue;
                    }
                    if (!next && !prev && (i > 1 && s[i] == s[i - 2])) {
                        continue;
                    }
                    dp[i + 1][last][next] = min(dp[i + 1][last][next], dp[i][prev][last] + next);
                }
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ans = min(ans, dp[n][i][j]);
        }
    }
    cout << ans << '\n';
}

signed main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    int T = 1;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}