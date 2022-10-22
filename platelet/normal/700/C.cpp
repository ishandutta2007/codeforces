#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#define upd(a, b) (a = min(a, b))

using namespace std;
const int N = 1005, M = 30005;
int n, m, s, t;
int len, path[N];
int idx, w[M], cut[M], dfn[N], fa[N], ls[N];
vector <pair <int, int>> G[N];
int dfs(int u, int del) {
	int lowu = dfn[u] = ++idx;
	for(auto [v, i] : G[u]) if(i ^ del) if(!dfn[v])
		fa[v] = u, ls[v] = i, upd(lowu, dfs(v, del));
	else if(i ^ ls[u] && dfn[v] < dfn[u]) upd(lowu, dfn[v]);
	cut[u] = lowu == dfn[u];
	return lowu;
}
int find(int u, int d) {
	if(u == t) return d - 1;
	dfn[u] = 1;
	for(auto [v, i] : G[u]) if(!dfn[v]) {
		path[d] = i;
		int re = find(v, d + 1);
		if(re) return re;
	}
	return 0;
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m >> s >> t;
	int u, v;
	rep(i, 1, m) scanf("%d%d%d", &u, &v, &w[i]), G[u].eb(v, i), G[v].eb(u, i);
	int len = find(s, 1);
	if(!len) puts("0\n0"), exit(0);
	int as = INT_MAX, cn, a, b;
	rep(i, 0, len) {
		int j = path[i];
		mem(dfn, 0), mem(cut, 0), dfs(s, j);
		if(dfn[t]) {
			for(int x = t; x ^ s; x = fa[x]) if(cut[x]) {
				int v = w[j] + w[ls[x]];
				if(v < as) cn = j ? 2 : 1, a = ls[x], b = j, as = v;
			}
		} else if(w[j] < as) cn = 1, a = j, as = w[j];
	}
	if(as == INT_MAX) puts("-1");
	else {
		printf("%d\n%d\n%d", as, cn, a);
		if(cn > 1) printf(" %d", b);
	}
	return 0;
}