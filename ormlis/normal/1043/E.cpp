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

const int INFi = 1e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n);
    range(i, n) cin >> x[i] >> y[i];
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](const int &i, const int &j) {
        return y[i] - x[i] < y[j] - x[j];
    });
    vector<int> pos(n);
    range(i, n) pos[ord[i]] = i;
    vector<vector<int>> g(n);
    range(_, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        u = pos[u];
        v = pos[v];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> py(n), sx(n);
    py[0] = y[ord[0]];
    for (int i = 1; i < n; ++i) py[i] = y[ord[i]] + py[i - 1];
    sx[n - 1] = x[ord[n - 1]];
    for (int i = n - 2; i >= 0; --i) sx[i] = x[ord[i]] + sx[i + 1];
    vector<ll> ans(n);
    range(i, n) {
        int X = x[ord[i]];
        int Y = y[ord[i]];
        ans[i] += 1ll * i * X;
        if (i) ans[i] += py[i - 1];
        ans[i] += 1ll * (n - i - 1) * Y;
        if (i + 1 < n) ans[i] += sx[i + 1];
        for(auto &j : g[i]) {
            if (j < i) {
                ans[i] -= X;
                ans[i] -= y[ord[j]];
            } else {
                ans[i] -= Y;
                ans[i] -= x[ord[j]];
            }
        }
    }
    range(i, n) cout << ans[pos[i]] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}