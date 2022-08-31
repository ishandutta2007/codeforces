#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int mod = 998244353;
const int N = 1.5e5 + 7;
int qpow(int x, int y) {
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int ny(int x) { return qpow(x, mod - 2); }
int n, nyn, m, siz[N], maxto[N], heavy[N], id[N], fa[N], idtot, lazy[N];
int sz[N];
void Add(int x, int y) { for(; x <= n; x += (x & -x)) (sz[x] += y) %= mod; }
int query(int x) { int res = 0; for(; x; x -= (x & -x)) (res += sz[x]) %= mod; return res; }
void add(int l, int r, int x) { if(l <= r) Add(l, x), Add(r + 1, mod - x); }
int head[N], edge_id;
struct node {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
void dfs1(int x) {
	siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa[x]) continue;
		fa[v] = x, dfs1(v), siz[x] += siz[v];
		if(siz[heavy[x]] < siz[v]) heavy[x] = v;
	}
}
void dfs2(int x) {
	id[x] = ++idtot;
	if(heavy[x]) maxto[heavy[x]] = maxto[x], dfs2(heavy[x]);
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa[x] || v == heavy[x]) continue;
		maxto[v] = v, dfs2(v);
	}
}
void change(int x, int y) {
	(lazy[x] += y) %= mod;
	add(1, id[x] - 1, 1ll * y * siz[x] % mod), add(id[x] + siz[x], n, 1ll * y * siz[x] % mod);
	if(heavy[x]) add(id[heavy[x]], id[heavy[x]] + siz[heavy[x]] - 1, 1ll * y * (n - siz[heavy[x]]) % mod);
}
int getans(int x) {
	int res = query(id[x]), sav = x;
	while(x) (res += 1ll * (n - siz[maxto[x]]) * lazy[fa[maxto[x]]] % mod) %= mod, x = fa[maxto[x]];
	return (1ll * res * nyn % mod + lazy[sav]) % mod;
}
int main() {
	scanf("%d%d", &n, &m), nyn = qpow(n, mod - 2);
	L(i, 1, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		add_edge(u, v), add_edge(v, u);
	}
	dfs1(1), maxto[1] = 1, dfs2(1);
	// cout << "maxto = " << maxto[5] << endl;
	while(m--) {
		int opt, x, y; scanf("%d%d", &opt, &x);
		if(opt == 1) scanf("%d", &y), change(x, y);
		if(opt == 2) printf("%d\n", getans(x));
	}	
	return 0;
}
/*
5 4
1 2
1 3
2 4
2 5
1 1 1
2 5
*/