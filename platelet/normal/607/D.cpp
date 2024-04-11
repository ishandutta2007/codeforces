#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define mid (l + r) / 2
#define lch l, mid, o * 2
#define rch mid + 1, r, o * 2 + 1

using namespace std;
const int N = 2e5 + 5, P = 1e9 + 7;
typedef long long ll;
int n = 1, w0, q, op[N], u[N], w[N]; vector <int> G[N];
int idx, fa[N], dfn[N], suf[N], d[N];
ll Pow(ll a, int n, ll r = 1) {
	for(; n; n /= 2, a = a * a % P) if(n & 1) r = r * a % P;
	return r;
}
void dfs(int u) { dfn[u] = ++idx; for(int v : G[u]) dfs(v); suf[u] = idx; }
ll c[N*4], tag[N*4];
void put(int o, ll v) { (c[o] *= v) %= P, (tag[o] *= v) %= P; }
void pushdown(int o) {
	if(tag[o] ^ 1) put(o * 2, tag[o]), put(o * 2 + 1, tag[o]), tag[o] = 1;
}
void pushup(int o) { c[o] = (c[o*2] + c[o*2+1]) % P; }
void upd(int L, int R, ll v, int l, int r, int o) {
	if(L <= l && r <= R) return put(o, v);
	pushdown(o);
	if(L <= mid) upd(L, R, v, lch);
	if(R > mid) upd(L, R, v, rch);
	pushup(o);
}
void add(int p, ll v, int l, int r, int o) {
	if(l == r) return c[o] = v, void();
	pushdown(o);
	if(p <= mid) add(p, v, lch); else add(p, v, rch);
	pushup(o);
}
int qry(int L, int R, int l, int r, int o) {
	if(L <= l && r <= R) return c[o];
	int res = 0; pushdown(o);
	if(L <= mid) res += qry(L, R, lch);
	if(R > mid) res += qry(L, R, rch);
	return res % P;
}
int qry(int p, int l, int r, int o) {
	if(l == r) return tag[o];
	pushdown(o);
	return p <= mid ? qry(p, lch) : qry(p, rch);
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> w[1] >> q;
	rep(i, 1, q) {
		scanf("%d%d", &op[i], &u[i]);
		if(op[i] == 1) scanf("%d", &w[++n]), G[fa[n] = u[i]].push_back(n);
	}
	dfs(1); int sz = 1;
	rep(i, 1, n * 4) tag[i] = 1;
	rep(i, 1, n) d[i] = 1;
	add(1, w[1], 1, n, 1);
	rep(i, 1, q) {
		int o = u[i];
		if(op[i] == 1) {
			sz++, add(dfn[sz], 1LL * w[sz] * qry(dfn[o], 1, n, 1) % P, 1, n, 1);
			upd(dfn[o], suf[o], (d[o] + 1) * Pow(d[o], P - 2) % P, 1, n, 1), d[o]++;
		} else printf("%lld\n", qry(dfn[o], suf[o], 1, n, 1) * (o > 1 ? Pow(qry(dfn[fa[o]], 1, n, 1), P - 2) : 1LL) % P);
	}
	return 0;
}