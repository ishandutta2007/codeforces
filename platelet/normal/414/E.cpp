#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ull = unsigned long long;

const int N = 2e5 + 5;

int n, q, rt, lc[N], rc[N], s[N], f[N];
int sum[N], mn[N], mx[N];
vector<int> G[N / 2];
int idx, seq[N];

ull fn(ull x) {
	const ull k = 0x9ddfea08eb382d69ULL;
	x *= k, x ^= x >> 47;
	x *= k, x ^= x >> 47;
	x *= k, x ^= x >> 47;
	return x * k;
}
int rand(int mod) {
	static ull s = 2;
	return (s += fn(s)) % mod;
}
int pu(int o) {
	s[o] = s[lc[o]] + s[rc[o]] + 1;
	sum[o] = sum[lc[o]] + sum[rc[o]] + (o <= n ? 1 : -1);
	mn[o] = min(mn[lc[o]], sum[o] - sum[rc[o]] + mn[rc[o]]);
	mx[o] = max(mx[lc[o]], sum[o] - sum[rc[o]] + mx[rc[o]]);
	return o;
}
void spt(int o, int k, int& u, int& v) {
	if(!o) return void(u = v = 0);
	if(k <= s[lc[o]]) spt(lc[v = o], k, u, lc[o]), f[lc[o]] = o, pu(o);
	else spt(rc[u = o], k - s[lc[o]] - 1, rc[o], v), f[rc[o]] = o, pu(o);
}
int mrg(int u, int v) {
	if(!u || !v) return u + v;
	if(rand(s[u] + s[v]) < s[u])
		return rc[u] = mrg(rc[u], v), f[rc[u]] = u, pu(u);
	return lc[v] = mrg(u, lc[v]), f[lc[v]] = v, pu(v);
}
int rk(int o) {
	int r = s[lc[o]] + 1;
	for(; o != rt; o = f[o]) if(o == rc[f[o]]) r += s[f[o]] - s[o];
	return r;
}
void bld(int l, int r, int& o) {
	if(l > r) return;
	int m = l + r >> 1;
	o = seq[m], bld(l, m - 1, lc[o]), bld(m + 1, r, rc[o]);
	f[lc[o]] = f[rc[o]] = o, pu(o);
}
void dfs(int u) {	
	seq[++idx] = u;
	for(int v : G[u]) dfs(v);
	seq[++idx] = u + n;
}
int kfa(int o, int k) {
	while(1) if(-mn[lc[o]] >= k) o = lc[o];
	else if(sum[rc[o]] - sum[o] == k) return o;
	else k -= sum[rc[o]] - sum[o], o = rc[o];
}
int qry(int k) {
	int o = rt;
	while(1) if(mx[lc[o]] >= k) o = lc[o];
	else if(sum[o] - sum[rc[o]] == k) return o;
	else k -= sum[o] - sum[rc[o]], o = rc[o];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	rep(i, 1, n) {
		int k, x; cin >> k;
		while(k--) cin >> x, G[i].pb(x);
		reverse(G[i].begin(), G[i].end());
	}
	dfs(1), bld(1, idx, rt);
	int op, a, b, x, y, z;
	while(q--) {
		cin >> op;
		if(op == 1) {
			cin >> a >> b;
			int ra = rk(a), rb = rk(b);
			if(ra > rb) swap(a, b), swap(ra, rb);
			spt(rt, rb, y, z), spt(y, ra, x, y);
			cout << sum[y] - mn[y] * 2 << '\n';
			rt = mrg(mrg(x, y), z);
		}
		if(op == 2) {
			cin >> a >> b;
			spt(rt, rk(a + n), y, z), spt(y, rk(a) - 1, x, y);
			int fa = kfa(z, b) - n;
			rt = mrg(x, z), spt(rt, rk(fa), x, z);
			rt = mrg(mrg(x, y), z);
		}
		if(op == 3) cin >> a, cout << qry(a + 1) << '\n';
	}
}