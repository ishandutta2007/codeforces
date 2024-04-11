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

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    range(i, n) cin >> a[i];
    if (n == 1) {
        cout << "1\n";
        return;
    }
    vector<pair<ll, int>> gcds;
    int ans = 1;
    gcds = {{abs(a[1] - a[0]), 0}};
    if (gcds.back().first != 1) ans = 2;
    for (int i = 2; i < n; ++i) {
        ll cur = abs(a[i] - a[i - 1]);
        vector<pair<ll, int>> newg;
        for (auto &[g, j] : gcds) {
            ll g2 = __gcd(g, cur);
            if (newg.empty() || newg.back().first != g2) {
                newg.emplace_back(g2, j);
            }
        }
        if (newg.back().first != cur) {
            newg.emplace_back(cur, i - 1);
        }
        if (newg[0].first != 1) {
            ans = max(ans, i - newg[0].second + 1);
        } else if (newg.size() >= 2) {
            ans = max(ans, i - newg[1].second + 1);
        }
        swap(newg, gcds);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}