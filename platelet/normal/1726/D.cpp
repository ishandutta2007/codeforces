#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back

template<class T> T& cmin(T& a, const T& b) { if(b < a) a = b; return a; }
template<class T> T& cmax(T& a, const T& b) { if(a < b) a = b; return a; }

#ifndef local
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

using namespace std;

const int N = 2e5 + 5;

int n, m, idx, dfn[N], f[N];
bool ans[N];
vector<pair<int, int>> G[N];
vector<tuple<int, int, int>> edge;

void dfs(int u, int fa) {
    dfn[u] = ++idx, f[idx] = fa;
    for(auto [v, i] : G[u]) if(!dfn[v]) {
        dfs(v, i);
    } else if(i != fa && dfn[v] < dfn[u]) edge.eb(u, v, i);
}
void solve() {
    cin >> n >> m;
    rep(i, 1, n) dfn[i] = 0, G[i].clear();
    rep(i, 1, m) ans[i] = 0;
    int u, v;
    rep(i, 1, m) cin >> u >> v, G[u].eb(v, i), G[v].eb(u, i);
    idx = 0, edge.clear(), dfs(1, 0);
    set<int> node;
    for(auto [u, v, i] : edge) node.insert(u), node.insert(v);
    for(auto [u, v, i] : edge) ans[i] = 1;
    if(node.size() == edge.size()) {
        int mx = 0;
        for(int u : node) cmax(mx, dfn[u]);
        ans[f[mx]] = 1;
        mx = 0;
        int p = 0;
        for(auto [u, v, i] : edge) if(dfn[u] + dfn[v] > mx)
            p = i, mx = dfn[u] + dfn[v];
        ans[p] = 0;
    }
    rep(i, 1, m) cout << ans[i];
    cout << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) solve();
}