#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define uint unsigned int 
using namespace std;
const int N = 1 << 18;
int n, q, dfn[N], en[N], mp[N], fa[N], idt, up[20][N], dep[N];
ll dis[N];
int ehd[N], ev[N], ew[N], enx[N], eid;
void eadd (int u, int v, int w) {
	++eid, ev[eid] = v, ew[eid] = w, enx[eid] = ehd[u], ehd[u] = eid;
}
int ww[N];
void add (int x, int w) {
	for (; x <= n; x += x & -x) ww[x] += w;
}
int query (int x) {
	int ret = 0;
	for (; x; x -= x & -x) ret += ww[x];
	return ret;
}
int sum (int l, int r) {
	return query (r) - query (l - 1);
}
void dfs (int x) {
	dfn[x] = ++idt;
	mp[idt] = x;
	for (int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa[x]) 
		dis[ev[i]] = dis[x] + ew[i], dep[ev[i]] = dep[x] + 1, fa[ev[i]] = x, dfs (ev[i]);
	en[x] = idt;
}
char s[N];
int findp (int w) { // num = p 
	int x = 0;
	R(i, 18, 0) if(x + (1 << i) <= n && ww[x + (1 << i)] < w) 
		x += 1 << i, w -= ww[x];
	return x + 1;
}
int lca (int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	R(i, 18, 0) if((dep[x] - dep[y]) >= (1 << i)) x = up[i][x];
	if(x == y) return x;
	R(i, 18, 0) if(up[i][x] != up[i][y]) x = up[i][x], y = up[i][y];
	return fa[x];
}
ll calc (int x) { // x isn't in S
	int all = query (n), S = sum(dfn[x], en[x]);
	if(!all) return 0;
	if(S == all) {
		int a = mp[findp(1)], b = mp[findp(all)];
//		cout << x << " : " << a << ' ' << b << '\n';
		return dis[lca(a, b)] - dis[x];
	}
	if(S) return 0;
	int p = 1, nu = query (dfn[x]);
	if(nu > 0) p = lca(x, mp[findp(nu)]);
	if(nu < all) {
		int c = lca(x, mp[findp(nu + 1)]);
		if(dep[c] > dep[p]) p = c;
	} 
//	cout << x << " : " << p << '\n';
	S = sum(dfn[p], en[p]);
	if(S != all) return dis[x] - dis[p];
	int a = mp[findp(1)], b = mp[findp(all)];
	return dis[lca(a, b)] - dis[p] + dis[x] - dis[p];
}
ll ns;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		eadd (u, v, w);
		eadd (v, u, w);
	}
	dfs (1);
	L(i, 1, n) up[0][i] = fa[i];
	L(i, 1, 18) L(j, 1, n) up[i][j] = up[i - 1][up[i - 1][j]];
	cin >> q;
	while (q--) {
		cin >> (s + 1);
		if(s[1] == '?') {
			cout << ns << '\n';
			continue;
		}
		int x;
		cin >> x;
		if(s[1] == '+') 
			ns += calc (x), add (dfn[x], 1);
		if(s[1] == '-') 
			add (dfn[x], -1), ns -= calc (x);
	}
	return 0;
}