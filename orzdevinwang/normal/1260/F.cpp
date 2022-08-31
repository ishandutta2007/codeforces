#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
int qpow(int x, int y) {
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int ny(int x) { return qpow(x, mod - 2); }
int sum[N << 2], lazy[N << 2];
void ADD(int id, int L, int R, int val) { (lazy[id] += val) %= mod, (sum[id] += 1ll * (R - L + 1) * val % mod) %= mod; } 
void pushdown(int id, int L, int R) {
	int mid = (L + R) / 2;
	ADD(id << 1, L, mid, lazy[id]), ADD(id << 1 | 1, mid + 1, R, lazy[id]), lazy[id] = 0;
}
void add(int id, int L, int R, int l, int r, int val) {
	if(l <= L && R <= r) return ADD(id, L, R, val), void();
	pushdown(id, L, R);
	int mid = (L + R) / 2;
	if(l <= mid) add(id << 1, L, mid, l, r, val);
	if(r > mid) add(id << 1 | 1, mid + 1, R, l, r, val);
	sum[id] = (sum[id << 1] + sum[id << 1 | 1]) % mod;
}
int query(int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return sum[id];
	pushdown(id, L, R);
	int mid = (L + R) / 2, res = 0;
	if(l <= mid) (res += query(id << 1, L, mid, l, r)) %= mod;
	if(r > mid) (res += query(id << 1 | 1, mid + 1, R, l, r)) %= mod;
	return res;
}
int n;
int head[N], edge_id;
struct node {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
int dep[N], heavy[N], siz[N], fa[N], maxto[N], id[N], idtot;
void dfs1(int x) {
	dep[x] = dep[fa[x]] + 1;
	siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa[x]) continue;
		fa[v] = x, dfs1(v), siz[x] += siz[v];
		if(siz[v] > siz[heavy[x]]) heavy[x] = v;
	}
}
void dfs2(int x) {
	id[x] = ++idtot;
	if(heavy[x]) maxto[heavy[x]] = maxto[x], dfs2(heavy[x]);
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(heavy[x] == v || fa[x] == v) continue;
		maxto[v] = v, dfs2(v);
	}
}
int L[N], R[N], w[N], nyw[N], Mul = 1, suma, sumb, now, ans;
void Add(int x, int val) { 
	for(; x; x = fa[maxto[x]]) add(1, 1, n, id[maxto[x]], id[x], val); 
}
int Query(int x) {
	int res = 0;
	for(; x; x = fa[maxto[x]]) (res += query(1, 1, n, id[maxto[x]], id[x])) %= mod;
	return res;
}
void ins(int x) {
	(now += 1ll * suma * nyw[x] % mod) %= mod;
	(now += 1ll * nyw[x] * dep[x] % mod * sumb % mod) %= mod;
	(now += mod - 2ll * nyw[x] % mod * Query(x) % mod) %= mod;
	Add(x, nyw[x]);
	(suma += 1ll * nyw[x] * dep[x] % mod) %= mod;
	(sumb += nyw[x]) %= mod;
}
void del(int x) {
	(sumb += mod - nyw[x]) %= mod;
	(suma += mod - 1ll * nyw[x] * dep[x] % mod) %= mod;
	Add(x, mod - nyw[x]);
	(now += 2ll * nyw[x] % mod * Query(x) % mod) %= mod;
	(now += mod - 1ll * nyw[x] * dep[x] % mod * sumb % mod) %= mod;
	(now += mod - 1ll * suma * nyw[x] % mod) %= mod;
}
vector<int> Ins[N], Del[N];
int main() {
	scanf("%d", &n);
	L(i, 1, n) {
		scanf("%d%d", &L[i], &R[i]), w[i] = R[i] - L[i] + 1;
		Mul = 1ll * Mul * w[i] % mod, nyw[i] = ny(w[i]);
		Ins[L[i]].push_back(i), Del[R[i]].push_back(i);
	}
	L(i, 1, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		add_edge(u, v), add_edge(v, u);
	}
	dfs1(1), maxto[1] = 1, dfs2(1);
	L(i, 1, 100000) {
		for(int x : Ins[i]) ins(x);
		(ans += now) %= mod;
		for(int x : Del[i]) del(x);
	}
	ans = 1ll * ans * Mul % mod;
	printf("%d\n", ans);
	return 0;
}