#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;


struct FT {
    vector<int> bit;
    FT(int n) : bit(n, MOD) {}
    FT(){}
    void upd(int i, int x) {
        for (; i < sz(bit); i |= i+1) bit[i] = min(bit[i], x);
    }
    int qry(int r) {
        int ans = MOD;
        for (++r; r > 0; r &= r-1) ans = min(ans, bit[r-1]);
        return ans;
    }
};

int n, d[N], ans[N];
vector<int> adj[N];
bool can[N];

bool blocked[N];
int sub[N];

vector<pair<int, int>> up, down;

void dfs_down(int c, int p, int sum, int mn) {
    mn = min(mn, sum);
    if (can[c]) {
        down.emplace_back(-mn, d[c]);
    }
    for (auto nxt : adj[c]) if (nxt != p && !blocked[nxt] && d[c] >= d[nxt]) {
        dfs_down(nxt, c, sum + (d[nxt] == d[c] ? -1 : +1), mn);
    }
}
void dfs_up(int c, int p, int sum, int mn) {
    if (mn >= 0) {
        up.emplace_back(sum, c);
    }
    for (auto nxt : adj[c]) if (nxt != p && !blocked[nxt] && d[c] <= d[nxt]) {
        int x = (d[nxt] == d[c] ? -1 : +1);
        dfs_up(nxt, c, x + sum, min(x, x + mn));
    }
}
void solve_cent(int c) {
    int m = sub[c];
    FT cnt(m);

    auto upd = [&](int i, int x) {
        cnt.upd(i, x);
    };
    auto qry = [&](int r) {
        return cnt.qry(r);
    };

    for (auto nxt : adj[c]) if (!blocked[nxt]) {
        int cost = d[nxt] == d[c] ? -1 : +1;

        down.clear(), up.clear();
        if (d[c] >= d[nxt]) dfs_down(nxt, c, cost, 0);
        if (d[c] <= d[nxt]) dfs_up(nxt, c, cost, cost);

        for (auto [x, v] : up) {
            ans[v] = min(ans[v], qry(x));
            if (can[c]) {
                ans[v] = min(ans[v], d[c]);
            }
        } 
        for (auto [x, v] : down) {
            upd(x, v);
            if (x <= 0) {
                ans[c] = min(ans[c], v);
            }
        }
    }
}

int dfs_sub(int u, int p) {
    sub[u] = 1;
    for (auto v : adj[u]) if (v != p && !blocked[v]) sub[u] += dfs_sub(v,u);
    return sub[u];
}
int dfs_centroid(int u, int p, int sz) {
    for (auto v : adj[u])  if (v != p && !blocked[v] && sub[v] > sz/2) return dfs_centroid(v,  u, sz);
    return u;
}
void build(int u = 0, int p = -1) {
    int sz = dfs_sub(u, p);
    int cent = dfs_centroid(u, p, sz);

    for (int rep = 0; rep < 2; rep++) {
        solve_cent(cent);
        reverse(adj[cent].begin(), adj[cent].end());
    }

    blocked[cent] = 1;
    for (auto nxt : adj[cent]) if (!blocked[nxt]) build(nxt, cent);
}

void solve() {
    cin >> n;

    vector<int> q; q.reserve(n);
    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        if (b) d[i] = 0, q.push_back(i);
        else d[i] = MOD;
    }

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }

    for (int rep = 0; rep < sz(q); rep++) {
        int c = q[rep];
        for (auto nxt : adj[c]) if (d[nxt] > d[c] + 1) {
            d[nxt] = d[c] + 1;
            q.push_back(nxt);
        }
    }
    for (int c = 0; c < n; c++) {
        for (auto nxt : adj[c]) if (d[nxt] == d[c]) {
            can[c] = 1;
        }
    }
    for (int i = 0; i < n; i++) ans[i] = d[i];
    build();

    for (int i = 0; i < n; i++) {
        cout << 2 * d[i] - ans[i] << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}