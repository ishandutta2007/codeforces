#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;
 
int n, m, par[MAXN], depth[MAXN];
bool val[MAXN];
vector<int> adj[MAXN], tree[MAXN], col[MAXN];
bool vis[MAXN];
ar<int, 2> qs[MAXN];

void dfs(int c) {
    vis[c] = 1;
    for (auto nxt : adj[c]) if (!vis[nxt]) {
        par[nxt] = c, depth[nxt] = depth[c] + 1;
        dfs(nxt);

        tree[c].push_back(nxt);
        tree[nxt].push_back(c);
    }
}
void path(int c, int p, int end, vector<int>& v) {
    if (sz(v) && v.back() == end) return;
    v.push_back(c);
    for (auto nxt : tree[c]) if (nxt != p)
        path(nxt, c, end, v);
    if (sz(v) && v.back() == end) return;
    v.pop_back();
}
int build(int c, int p) {
    int ans = 0, child = 0;
    for (auto nxt : tree[c]) if (nxt != p) {
        ans += build(nxt, c);
        child += val[nxt];
    }
    ans -= child / 2;
    if (child % 2 == 0 && val[c]) {
        ans++;
    }
    return ans;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs(0);
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b, --a, --b;
        qs[i] = {a, b};
        while (a != b) {
            if (depth[a] < depth[b]) swap(a, b);
            val[a] ^= 1;
            a = par[a];
        }
    }
    bool bad = 0;
    for (int i = 0; i < n; i++) bad |= val[i];

    if (!bad) {
        cout << "YES\n";
        for (int i = 0; i < q; i++) {
            auto [a, b] = qs[i];
            vector<int> v;
            path(a, -1, b, v);

            cout << sz(v) << '\n';
            for (auto c : v) cout << c+1 << ' ';
            cout << '\n';
        }
        return;
    }
    cout << "NO\n";
    int ans = build(0, -1);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}