#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 4e5 + 7;
const int mod = 1e9 + 7; 
int qpow(int x, int y) {
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
} 
int ny(int x) { 
	return qpow(x, mod - 2);
}
int p[N], TOT, mu[N], phi[N], g[N], inv[N];
bool Prime[N];
void xxs(int x) {
	inv[1] = mu[1] = phi[1] = 1;
	L(i, 2, x) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod; 
	L(i, 2, x) {
		if(!Prime[i]) p[++TOT] = i, mu[i] = -1, phi[i] = i - 1;
		for(int j = 1; p[j] * i <= x && j <= TOT; j ++) {
			Prime[p[j] * i] = 1;
			if(i % p[j] == 0) {
				mu[p[j] * i] = 0;
				phi[p[j] * i] = phi[i] * p[j];
				break;
			}
			mu[p[j] * i] = -mu[i], phi[p[j] * i] = phi[i] * phi[p[j]];
		} 
	}
	L(i, 1, x) L(j, 1, x / i) (g[i * j] += 1ll * inv[phi[i]] * i % mod * (mu[j] + mod) % mod) %= mod; 
}
int n, m, k, fa[N], id[N], a[N], DY[N], idtot;
int maxto[N], dep[N], heavy[N], siz[N];
int head[N], edge_id;
struct node {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
int hed[N], edgeid;
struct edge {
	int to, next;
} E[N << 1];
void addedge(int u, int v) {
	++edgeid, E[edgeid].next = hed[u], E[edgeid].to = v, hed[u] = edgeid;
}
void dfs1(int x) {
	siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa[x]) continue;
		fa[v] = x, dep[v] = dep[x] + 1, dfs1(v), siz[x] += siz[v];
		if(siz[v] > siz[heavy[x]]) heavy[x] = v;
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
int lca(int x, int y) {
	while(maxto[x] ^ maxto[y]) {
		if(dep[maxto[x]] < dep[maxto[y]]) swap(x, y);
		x = fa[maxto[x]];
	}
	if(dep[x] < dep[y]) swap(x, y);
	return y;
}
bool cmp(int x, int y) { return id[x] < id[y]; }
int f[N], flag[N], stk[N], tot;
void insert(int x) {
	hed[x] = 0;
	if(!tot) return stk[++tot] = x, void();
	int LCA = lca(stk[tot], x);
	if(LCA == stk[tot]) return stk[++tot] = x, void();
	while(tot > 1 && dep[LCA] < dep[stk[tot - 1]]) addedge(stk[tot - 1], stk[tot]), --tot;
	if(LCA ^ stk[tot - 1]) hed[LCA] = 0, addedge(LCA, stk[tot]), stk[tot] = LCA;
	else addedge(LCA, stk[tot]), --tot;
	stk[++tot] = x;
} 
int ans, All;
int sum[N];
void DP(int x) {
	if(flag[x]) sum[x] = phi[a[x]], (All += mod - 1ll * dep[x] * phi[a[x]] % mod * phi[a[x]] % mod) %= mod;
	else sum[x] = 0;
	for(int i = hed[x]; i; i = E[i].next) {
		int v = E[i].to; DP(v);
		(All += mod - 2ll * dep[x] * sum[x] % mod * sum[v] % mod) %= mod; 
		(sum[x] += sum[v]) %= mod;
	}
}
int main() {
	scanf("%d", &n);
	xxs(n);
	L(i, 1, n) scanf("%d", &a[i]), DY[a[i]] = i;
	L(i, 1, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		add_edge(u, v), add_edge(v, u);
	} 
	dfs1(1), maxto[1] = 1, dfs2(1);
	L(i, 1, n) {
		int qwq = 0;
		edgeid = tot = All = 0;
		L(j, 1, n / i) f[j] = DY[i * j], (qwq += phi[a[f[j]]]) %= mod, flag[f[j]] = 1;
		L(j, 1, n / i) (All += 1ll * dep[f[j]] * phi[a[f[j]]] % mod * qwq % mod) %= mod;
		if(!flag[1]) insert(1); 
		sort(f + 1, f + (int)(n / i) + 1, cmp);
		L(j, 1, n / i) insert(f[j]);
		while(tot > 1) addedge(stk[tot - 1], stk[tot]), --tot;
		DP(1);
		(All *= 2) %= mod;
		(ans += 1ll * All * g[i] % mod) %= mod;
		L(j, 1, n / i) flag[f[j]] = 0; 
	}
	ans = 1ll * ans * inv[n] % mod * inv[n - 1] % mod;
	printf("%d\n", ans);
	return 0;
}