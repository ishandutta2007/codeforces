#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define mid ((l + r) / 2)
#define lch l, mid, o * 2
#define rch mid + 1, r, o * 2 + 1

using namespace std;
const int N = 1e5 + 5;
int n, m, s, t, sp;
vector <int> G[N];
int vis[N], pre[N], suf[N];
int find(int u, int f) {
	vis[u] = 1;
	for(int v : G[u]) if(v ^ f) if(vis[v]) return s = v;
	else if(find(v, u)) return 1;
	return 0;
}
int d[N], sz[N], fa[N], son[N], idx, tp[N], dfn[N];
void dfs(int u) {
	sz[u] = 1;
	for(int v : G[u]) if(v ^ fa[u]) if(v == s) t = u;
	else if(!fa[v]) {
		d[v] = d[u] + 1, fa[v] = u;
		dfs(v), sz[u] += sz[v];
		if(sz[v] > sz[son[u]]) son[u] = v;
	}
}
void Dfs(int u, int top) {
	tp[u] = top, dfn[u] = ++idx;
	if(son[u]) Dfs(son[u], top);
	for(int v : G[u]) if(v ^ son[u] && fa[v] == u) Dfs(v, v);
}
int c[N * 4][2], tag[N * 4];
void pu(int o) {
	rep(i, 0, 1) c[o][i ^ tag[o]] = c[o * 2][i] + c[o * 2 + 1][i];
}
void bld(int l, int r, int o) {
	c[o][0] = r - l + 1;
	if(l < r) bld(lch), bld(rch);
}
void upd(int L, int R, int l, int r, int o) {
	if(L <= l && r <= R) { tag[o] ^= 1, swap(c[o][0], c[o][1]); return; }
	if(L <= mid) upd(L, R, lch);
	if(R > mid) upd(L, R, rch);
	pu(o);
}
int qry(int L, int R, int su, int l, int r, int o) {
	if(L <= l && r <= R) return c[o][su];
	su ^= tag[o];
	int re = 0;
	if(L <= mid) re += qry(L, R, su, lch);
	if(R > mid) re += qry(L, R, su, rch);
	return re;
}
void upd(int u, int v) {
	for(; tp[u] ^ tp[v]; u = fa[tp[u]]) {
		if(d[tp[u]] < d[tp[v]]) swap(u, v);
		upd(dfn[tp[u]], dfn[u], 1, n, 1);
	}
	if(d[u] > d[v]) swap(u, v);
	if(d[u] < d[v]) upd(dfn[u] + 1, dfn[v], 1, n, 1);
}
int lca(int u, int v) {
	for(; tp[u] ^ tp[v]; u = fa[tp[u]])
	if(d[tp[u]] < d[tp[v]]) swap(u, v);
	return d[u] < d[v] ? u : v;
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	int u, v;
	rep(i, 1, n) scanf("%d%d", &u, &v), G[u].pb(v), G[v].pb(u);
	find(1, 0), dfs(s), Dfs(s, s), bld(1, n, 1);
	for(int x = t; x ^ s; x = fa[x]) pre[x] = fa[x], suf[fa[x]] = x;
	pre[s] = t, suf[t] = s;
	while(m--) {
		scanf("%d%d", &u, &v);
		int uu = lca(u, t), vv = lca(v, t);
		if(uu == vv) upd(u, v);
		else if(d[uu] < d[vv]) {
			int d1 = d[u] + d[v] - d[uu] * 2, d2 = d[u] + 1 + d[v] + d[t] - 2 * d[vv];
			if(d1 < d2 || (d1 == d2 && suf[uu] < pre[uu])) upd(u, v);
			else upd(u, s), sp ^= 1, upd(v, t);
		} else {
			int d1 = d[u] + d[v] - d[vv] * 2, d2 = d[u] + d[t] - 2 * d[uu] + 1 + d[v];
			if(d1 < d2 || (d1 == d2 && pre[uu] < suf[uu])) upd(u, v);
			else upd(u, t), sp ^= 1, upd(v, s);
		}
		int re = 0, x = t;
		for(; tp[x] ^ s; x = fa[tp[x]]) re += qry(dfn[tp[x]], dfn[x], 1, 1, n, 1);
		if(x ^ s) re += qry(2, dfn[x], 1, 1, n, 1);
		printf("%d\n", n - c[1][1] - sp + (re == d[t] && sp));
	}
	return 0;
}