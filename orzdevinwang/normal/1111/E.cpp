#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define pll pair<ll, ll> 
#define mkp make_pair
using namespace std;
bool test11;
const int N = 2e5 + 7;
const int K = 303;
const int mod = 1e9 + 7;
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
void Addedge(int u, int v) {
	addedge(u, v), addedge(v, u);
}
int fa[N], dep[N], siz[N], maxto[N], heavy[N], id[N], idtot;
void dfs1(int x) {
	siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(fa[x] == v) continue;
		fa[v] = x, dep[v] = dep[x] + 1, dfs1(v), siz[x] += siz[v];
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
int lca(int x, int y) {
	while(maxto[x] ^ maxto[y]) {
		if(dep[maxto[x]] < dep[maxto[y]]) swap(x, y);
		x = fa[maxto[x]];
	}
	if(dep[x] < dep[y]) swap(x, y);
	return y;
}
int n, q, k, m, r, f[N], totk, stk[N], tot, flag[N];
void insert(int x) {
	hed[x] = 0;
	if(!tot) return stk[++tot] = x, void();
	int LCA = lca(stk[tot], x);
	if(LCA == stk[tot]) return stk[++tot] = x, void();
	while(tot > 1 && dep[LCA] < dep[stk[tot - 1]]) Addedge(stk[tot - 1], stk[tot]), --tot;
	if(LCA ^ stk[tot - 1]) hed[LCA] = 0, Addedge(LCA, stk[tot]), stk[tot] = LCA;
	else Addedge(LCA, stk[tot]), --tot;
	stk[++tot] = x;
}
bool cmp(int x, int y) { return id[x] < id[y]; }
int dp[K], h[N];
void DP(int x, int fa) {
	if(flag[x]) R(i, m, h[x]) (dp[i] = (dp[i - 1] + 1ll * (i - h[x]) * dp[i] % mod) % mod) %= mod;
	for(int i = hed[x]; i; i = E[i].next) {
		int v = E[i].to; if(v == fa) continue;
		h[v] = h[x] + flag[x], DP(v, x);
	}
}
int main() {
	scanf("%d%d", &n, &q);
	test11 = (n == 99999 && q == 50336);
	L(i, 1, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		add_edge(u, v), add_edge(v, u);
	}
	dfs1(1), maxto[1] = 1, dfs2(1);
	while(q--) {
		tot = edgeid = totk = 0;
		scanf("%d%d%d", &k, &m, &r);
		L(i, 1, k) scanf("%d", &f[++totk]), flag[f[totk]] = 1;
		f[++totk] = r;
		sort(f + 1, f + totk + 1, cmp);
		totk = unique(f + 1, f + totk + 1) - f - 1;
		L(i, 1, totk) insert(f[i]);
		while(tot > 1) Addedge(stk[tot], stk[tot - 1]), --tot; 
		L(i, 0, m) dp[i] = (i == 0);
		h[r] = 0, DP(r, -1);
		int sum = 0;
		L(i, 0, m) (sum += dp[i]) %= mod; 
		printf("%d\n", sum);
		L(i, 1, totk) flag[f[i]] = 0;
	}
	return 0;
}