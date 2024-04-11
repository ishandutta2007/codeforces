#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 2e5 + 5;
int n, m, q, idx, dfn[N], suf[N], cut[N];
vector <pair <int, int>> G[N];
int vis[N], sz[N], s[N], t[N], up[N], down[N];
int dfs(int u, int lst) {
	int lowu = dfn[u] = ++idx;
	for(auto [v, w] : G[u]) if(!dfn[v]) {
		int lowv = dfs(v, w);
		lowu = min(lowu, lowv), cut[v] = lowv > dfn[u];
	} else if(w ^ lst && dfn[v] < dfn[u]) lowu = min(lowu, dfn[v]);
	suf[u] = idx;
	return lowu;
}
void Dfs(int u) {
	vis[u] = 1;
	for(auto [v, w] : G[u]) if(!vis[v]) Dfs(v), sz[u] += sz[v];
}
void DFs(int u, int fa) {
	vis[u] = 1, up[u] = up[fa], down[u] = down[fa];
	if(!fa || (cut[u] && sz[u] <= 0)) up[u] = u;
	if(!fa || (cut[u] && sz[u] >= 0)) down[u] = u;
	for(auto [v, w] : G[u]) if(!vis[v]) DFs(v, u);
}
int main() {
	cin >> n >> m >> q; 
	int u, v;
	rep(i, 1, m) {
		scanf("%d%d", &u, &v);
		G[u].push_back({v, ++idx}), G[v].push_back({u, idx});
	}
	idx = 0;
	rep(i, 1, n) if(!dfn[i]) dfs(i, 0);
	rep(i, 1, q) scanf("%d%d", &s[i], &t[i]), sz[s[i]]++, sz[t[i]]--;
	rep(i, 1, n) if(!vis[i]) Dfs(i);
	mem(vis, 0);
	rep(i, 1, n) if(!vis[i]) DFs(i, 0);
	rep(i, 1, q) {
		int lca = dfn[up[s[i]]] > dfn[down[t[i]]] ? up[s[i]] : down[t[i]];
		if(dfn[s[i]] > dfn[t[i]]) swap(s[i], t[i]);
		if(dfn[s[i]] < dfn[lca] || dfn[t[i]] > suf[lca]) puts("No"), exit(0);
	}
	puts("Yes");
	return 0;
}