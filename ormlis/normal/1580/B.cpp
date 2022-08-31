#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
//const int md = 998244353;
const ll INF = 2e18;
const int maxN = 4000 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int md;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

const int T = 103;

int dp[T][T][T];
int C[T][T];

void solve() {
    int n, m, k;
    cin >> n >> m >> k >> md;
    dp[0][0][0] = 1;
    range(i, n + 1) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
        }
    }
    int val = 1;
    dp[1][0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        val = mul(val, i);
        dp[1][i][1] = val;
    }
    for (int M = 1; M < m; ++M) {
        range(L, n) {
            range(k1, k + 1) {
                if (!dp[M][L][k1]) continue;
                range(R, n - L) {
                    range(k2, k - k1 + 1) {
                        if (!dp[M][R][k2]) continue;
                        dp[M + 1][L + R + 1][k1 + k2] = add(dp[M + 1][L + R + 1][k1 + k2],
                                                            mul(C[L + R][L],
                                                                mul(dp[M][L][k1], dp[M][R][k2])));
                    }
                }
            }
        }
        dp[M + 1][0][0] = 1;
    }
    cout << dp[m][n][k] % md << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}