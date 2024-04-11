#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

ll solve(vector<pair<int, int>> &pts) {
    vector<vector<int>> cnt(2, vector<int>(2));
    int n = pts.size();
    for (auto[x, y] : pts) {
        x /= 2;
        y /= 2;
        cnt[x % 2][y % 2]++;
    }
    ll ans = 0;
    range(i, 2) {
        range(j, 2) {
            ll x = cnt[i][j];
            ans += 1ll * x * (x - 1) * (x - 2) / 6;
        }
    }
    range(i, 2) {
        range(j, 2) {
            ll x1 = cnt[i][j];
            ans += 1ll * x1 * (x1 - 1) / 2 * (n - x1);
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> pts(n);
    ll ans2 = 0, ans6 = 0;
    range(i, n) cin >> pts[i].first >> pts[i].second;
    for(auto [xi, yi] : pts) {
        vector<vector<vector<int>>> cnt(4, vector<vector<int>> (4, vector<int> (4)));
        for(auto [xj, yj] : pts) {
            if (xi == xj && yi == yj) continue;
            int xc = xj - xi;
            int yc = yj - yi;
            int gc = __gcd(abs(xc), abs(yc));
            cnt[gc % 4][((xc % 4) + 4) % 4][((yc % 4) + 4) % 4]++;
        }
        range(g1, 4) {
            range(x1, 4) {
                range(y1, 4) {
                    range(g2, 4) {
                        range(x2, 4) {
                            range(y2, 4) {
                                int s2 = x1 * y2 - y1 * x2;
                                if (s2 % 2) continue;
                                int g = g1 + g2;
                                if (g % 2) continue;
                                int can = cnt[g1][x1][y1] * cnt[g2][x2][y2];
                                if (g1 == g2 && x2 == x1 && y1 == y2) can -= cnt[g1][x1][y1];
                                if (x2 != x1 || y2 != y1) g += 2;
                                int v = (s2 / 2) + 1 - (g / 2);
                                if (v % 2) {
                                    if (g1 % 2) ans2 += can;
                                    else ans6 += can;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans2 / 2 + ans6 / 6 << '\n';
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