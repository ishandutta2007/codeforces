#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e5 + 7, B = 320;
int n, q, a[N], lst[N], up[20][N], dep[N], fa[N];
int ehd[N], ev[N], enx[N], eid;
void eadd(int u, int v) {
	enx[++eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
}
int dfn[N], en[N], idt, ord[N];
bool vis[N];
vi S;

vi upc[N], dwc[N];
ll ep[N];

int mxto[N], mxd[N], hv[N];
void dfs1(int u) {
	mxd[u] = 0;
	for(int i = ehd[u]; i; i = enx[i]) if(ev[i] != fa[u]) {
		dep[ev[i]] = dep[u] + 1, fa[ev[i]] = u, dfs1(ev[i]);
		if(mxd[ev[i]] + 1 > mxd[u]) mxd[u] = mxd[ev[i]] + 1, hv[u] = ev[i];
	}
}
void dfs2(int u) {
	dfn[u] = ++idt, ord[idt] = u;
	if(mxto[u] == u) {
		for(int i = u; i && sz(upc[u]) <= mxd[u]; i = fa[i]) 
			upc[u].push_back(i);
		for(int i = u; i && sz(dwc[u]) <= mxd[u]; i = hv[i]) 
			dwc[u].push_back(i);
	}
	
	if(hv[u]) mxto[hv[u]] = mxto[u], dfs2(hv[u]);
	for(int i = ehd[u]; i; i = enx[i]) if(ev[i] != hv[u] && ev[i] != fa[u]) 
		mxto[ev[i]] = ev[i], dfs2(ev[i]);
	en[u] = idt;
}

int lg[N];
inline int qry (int x, int k) {
	if(k == 0) return x;
	int z = lg[k], tdep = dep[x] - k;
    x = mxto[up[z][x]];
	if(dep[x] <= tdep) return dwc[x][tdep - dep[x]];
	else return upc[x][dep[x] - tdep];
}
int lca (int u, int v) {
	if(dep[u] < dep[v]) swap (u, v);
	int t = dep[u] - dep[v];
	R(i, 19, 0) if(t >> i & 1) u = up[i][u];
	if(u == v) return u;
	R(i, 19, 0) if(up[i][u] != up[i][v]) 
		u = up[i][u], v = up[i][v];
	return fa[u];
}

inline int get (int x, int t) {
	if(dfn[x] < dfn[t] && dfn[t] <= en[x]) {
		int z = qry(t, dep[t] - dep[x] - 1);
		return max(abs(a[x] - a[z]), abs(a[x] + a[z])) - 
			max(abs(lst[x] - lst[z]), abs(lst[x] + lst[z]));
	} else return 0;
} 
void rebuild () {
	memset(vis, 0, sizeof(vis));
	L(i, 2, n) {
		int u = ord[i];
		ep[u] = ep[fa[u]] + max(abs (a[u] - a[fa[u]]), abs (a[u] + a[fa[u]]));
	}
	L(i, 1, n) lst[i] = a[i];
	S.clear();
}
ll query (int x) {
	ll ret = ep[x];
	for (const int &i : S) ret += get (i, x);
	return ret;
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	L(i, 2, n) lg[i] = lg[i - 1] + ((i & -i) == i);
	L(i, 1, n) cin >> a[i];
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		eadd(u, v), eadd(v, u);
	}
	dep[1] = 1, dfs1(1), mxto[1] = 1, dfs2(1);
	L(i, 1, n) up[0][i] = fa[i];
	L(i, 1, 19) L(j, 1, n) up[i][j] = up[i - 1][up[i - 1][j]];
	rebuild();
	while (q--) {
		int op, x, y;
		cin >> op >> x >> y;
		if(op == 1) {
			a[x] = y;
			if(!vis[x]) S.push_back(x), vis[x] = true;
			if(fa[x] && !vis[fa[x]]) S.push_back(fa[x]), vis[fa[x]] = true;
			if(sz(S) > 200) rebuild();
//			rebuild();
		}
		else {
			int lc = lca (x, y);
			cout << query(x) + query(y) - query (lc) * 2 << '\n';
		}
	}
	return 0;
}