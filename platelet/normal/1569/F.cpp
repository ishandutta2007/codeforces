#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;
using arr = array<int8_t, 13>;

set<tuple<arr, int, int>> vs;
set<arr> s1, s2;
int n, m, k, G[13][13];
void dfs(arr fa, int u, int v) {
    if(u > v) swap(u, v);
    fa[v] = u;
    if(vs.count(make_tuple(fa, u, v))) return;
    vs.insert(make_tuple(fa, u, v));
    bool vs[13] = {};
    rep(i, 1, n) if(fa[i]) vs[i] = vs[fa[i]] = 1;
    if(*min_element(vs + 1, vs + n + 1)) {
        if(G[u][v]) s1.insert(fa);
        return;
    }
    rep(nu, 1, n) if(G[u][nu] && !vs[nu])
    rep(nv, 1, n) if(G[v][nv] && !vs[nv] && nu ^ nv) dfs(fa, nu, nv);
}
void Dfs(arr fa, int i) {
    while(i <= n && fa[i]) i++;
    if(i > n) {
    	rep(i, 1, n) if(fa[fa[i]]) fa[i] = fa[fa[i]];
    	return void(s2.insert(fa));
    }
    vector<int> v;
    rep(j, i + 1, n) if(!fa[j]) v.pb(j);
    For(S, 0, 1 << v.size()) {
        arr nw = fa;
        For(j, 0, v.size()) if(S >> j & 1) nw[v[j]] = i;
        Dfs(nw, i + 1);
    }
}

int main() {
#ifdef local
    freopen(".in", "r", stdin);
#endif
    cin >> n >> m >> k;
    int u, v;
    rep(i, 1, n) G[0][i] = G[i][0] = 1;
    while(m--) scanf("%d%d", &u, &v), G[u][v] = G[v][u] = 1;
    dfs(arr(), 0, 0);
    for(const arr& fa : s1) Dfs(fa, 1);
    int as[7] = {};
    for(const arr& fa : s2) {
        int ct = 0;
        rep(i, 1, n) ct += !fa[i];
        as[ct]++;
    }
    ll su = 0, t = 1;
    rep(i, 1, 6) t *= k--, su += as[i] * t;
    cout << su;
}