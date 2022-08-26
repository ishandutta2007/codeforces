#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

void solve() {
    int n;
    cin >> n;
    const int K = 200;
    vector<ar<int, 2>> dp(K + 1);
    dp[0][0] = 1;
    range(i, n) {
        int x;
        cin >> x;
        vector<ar<int, 2>> newdp(K + 1);
        if (x == -1) {
            range(was, K + 1) {
                range(b, 2) {
                    if (dp[was][b] == 0) continue;
                    newdp[K][0] = add(newdp[K][0], dp[was][b]);
                    newdp[was][0] = sub(newdp[was][0], dp[was][b]);
                    newdp[was][1] = add(newdp[was][1], dp[was][b]);
                    if (was) newdp[was - 1][1] = sub(newdp[was - 1][1], dp[was][b]);
                    if (b == 1 && was) {
                        newdp[was - 1][1] = add(newdp[was - 1][1], dp[was][b]);
                    }
                }
            }
            for (int j = K; j >= 1; --j) {
                range(b, 2) {
                    newdp[j - 1][b] = add(newdp[j][b], newdp[j - 1][b]);
                }
            }
            swap(dp, newdp);
        } else {
            range(was, K + 1) {
                if (was < x) {
                    newdp[x][0] = add(newdp[x][0], add(dp[was][0], dp[was][1]));
                } else if (was == x) {
                    newdp[x][1] = add(newdp[x][1], add(dp[x][1], dp[x][0]));
                } else {
                    newdp[x][1] = add(newdp[x][1], dp[was][1]);
                }
            }
            swap(dp, newdp);
        }
        dp[0][0] = dp[0][1] = 0;
    }
    int ans = 0;
    range(i, K + 1) ans = add(ans, dp[i][1]);
    cout << ans << '\n';
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