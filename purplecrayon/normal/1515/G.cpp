#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

struct SCC {
    int n;
	vector<vector<int>> adj, radj, comp;
	vector<int> order, who;
    vector<bool> used;
    int cc = 0;

    SCC(){ }
    SCC(int _n): n(_n), adj(_n), comp(_n), radj(_n) {}

    void dfs_top(int v) {
        used[v] = true;
        for (auto nxt : adj[v]) 
            if (!used[nxt])
                dfs_top(nxt);

        order.push_back(v);
    }
    void dfs_comp(int v) {
        used[v] = 1;
        comp[cc].push_back(v); 
        who[v] = cc;

        for (auto nxt : radj[v])
            if (!used[nxt]) 
                dfs_comp(nxt);
    }
    vector<pair<int, int>> ed;
    void add(int a, int b){
        adj[a].push_back(b), radj[b].push_back(a);
        ed.push_back({a, b});
    }
    void build() {
    	who.assign(n, -1); used.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (!used[i])
                dfs_top(i);
        }
        std::fill(used.begin(), used.end(), false);
        for (int i = 0; i < n; i++){
            int v = order[n-1-i];
            if (!used[v]) {
                dfs_comp(v);
                cc++;
            }
        }
    }
} g;


int n, m;
ll ans[N], root_path[N];
vector<ar<int, 2>> adj[N];
bool vis[N];

void dfs(int c) {
    vis[c] = 1;
    for (auto [nxt, w] : adj[c]) if (g.who[nxt] == g.who[c]) {
        if (vis[nxt]) {
            ans[g.who[c]] = std::gcd(ans[g.who[c]], root_path[c] - root_path[nxt] + w);
        } else {
            root_path[nxt] = root_path[c] + w;
            dfs(nxt);
        }
    }
}
void solve() {
    cin >> n >> m;

    g = SCC(n);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w, --a, --b;
        g.add(a, b);
        adj[a].push_back({b, w});
    }

    g.build();
    for (int i = 0; i < n; i++) if (!vis[i]) {
        dfs(i);
    }

    int q; cin >> q;
    while (q--) {
        int c, s, t; cin >> c >> s >> t, --c;
        s = (t - s) % t;
        if (s == 0) {
            cout << "YES\n";
            continue;
        }
        int can = std::gcd(t, ans[g.who[c]]);
        if (s % can) cout << "NO\n";
        else cout << "YES\n";
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}