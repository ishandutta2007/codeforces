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
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 5e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct convex_hull_trick {
    struct Line {
        ll k, b;

        ll get(ll x) {
            return k * x + b;
        }
    };

    vector<ll> xx;
    vector<Line> lines;

    ll intersect(Line &a, Line &b) {
        if (a.k == b.k) {
            if (a.b < b.b) return -INF;
            return INF;
        }
        // x = (a.b - b.b) / (b.k - a.k)
        if (a.b >= b.b) {
            return (a.b - b.b + (b.k - a.k - 1)) / (b.k - a.k);
        } else {
            return (a.b - b.b) / (b.k - a.k);
        }
    }

    void add(ll k, ll b) {
        Line A = {k, b};
        while (!lines.empty() && intersect(A, lines.back()) <= xx.back()) {
            xx.pop_back();
            lines.pop_back();
        }
        if (lines.empty()) {
            xx.push_back(-INF);
        } else {
            xx.push_back(intersect(A, lines.back()));
        }
        lines.push_back(A);
    }

    ll get(ll x) {
        int i = upper_bound(all(xx), x) - xx.begin();
        return lines[i - 1].get(x);
    }
};


vector<int> g[maxN];
ll dp[maxN];
int sz[maxN];
ll ans = INF;
int n;

void dfs(int v, int p) {
    sz[v] = 1;
    vector<int> can;
    for(auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        sz[v] += sz[u];
        can.push_back(u);
    }
    dp[v] = 1ll * sz[v] * sz[v];
    if (sz[v] == 1) return;
    // dp[w] + (k - sz[w]) ^ 2 + dp[u]
    // k = n - sz[u]
    // dp[w] + sz[w] ^ 2 - 2 * k * sz[w]
    sort(all(can), [&] (const int &a, const int &b) {
        return sz[a] < sz[b];
    });
    convex_hull_trick cht;
    cht.add(0, 0);
    for(auto &u : can) {
        ll k = n - sz[u];
        ans = min(ans, dp[u] + cht.get(k) + 1ll * k * k);
        cht.add(-2 * sz[u], 1ll * sz[u] * sz[u] + dp[u]);
        dp[v] = min(dp[v], dp[u] + 1ll * (sz[v] - sz[u]) * (sz[v] - sz[u]));
    }
}

void solve() {
    cin >> n;
    range(_, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    ll res = 1ll * n * n;
    ans += n;
    ans /= 2;
    cout << res - ans << '\n';
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