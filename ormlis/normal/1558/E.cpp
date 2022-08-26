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

const int INFi = 2e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 3e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n);
    range(i, n - 1) cin >> a[i + 1];
    range(i, n - 1) cin >> b[i + 1];
    ll s = 0;
    int ans = 0;
    vector<vector<pair<int, int>>> g(n);
    vector<int> U(m), V(m);
    range(i, m) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        U[i] = u;
        V[i] = v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    vector<bool> us(n);
    bool ok = true;
    us[0] = true;
    while(ok) {
        ok = false;
        vector<ll> dp(n, INF);
        vector<int> p(n, -1);
        vector<bool> was(n, false);
        set<ar<int, 3>> q;
        range(i, n) {
            for(auto &[u, j] : g[i]) {
                if (us[u] && u) {
                    if (U[j] == u) {
                        U[j] = 0;
                    } else {
                        V[j] = 0;
                    }
                    u = 0;
                }
            }
        }
        range(i, n) {
            if (!us[i]) continue;
            for(auto &[u, j] : g[i]) {
                if (!u) continue;
                q.insert({(int)max(0ll, 1ll * a[u] + 1 - s), u, j});
            }
        }
        was[0] = true;
        int f1 = -1, f2 = -1;
        while(!q.empty()) {
            auto [need, v, j] = *q.begin();
            q.erase(q.begin());
            ans = max(ans, need);
            if (was[v]) {
                f1 = v;
                f2 = U[j] ^ V[j] ^ v;
                ok = true;
                break;
            }
            was[v] = true;

            int from = U[j] ^ V[j] ^ v;
            p[v] = from;
            if (us[from]) {
                dp[v] = s + b[v];
            } else {
                dp[v] = dp[from] + b[v];
            }
            for(auto &[u, e] : g[v]) {
                if (e == j) continue;
                q.insert({(int)max(0ll, 1ll * a[u] + 1 - dp[v]), u, e});
            }
        }
        if (!ok) break;
        while(!us[f1]) {
            us[f1] = true;
            s += b[f1];
            f1 = p[f1];
        }
        while(!us[f2]) {
            us[f2] = true;
            s += b[f2];
            f2 = p[f2];
        }
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