#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define mid (l + r) / 2
#define lch l, mid, o * 2
#define rch mid + 1, r, o * 2 + 1

using namespace std;
const int N = 2e5 + 5;
int n, m, p[N], ip[N], u[N*4], v[N*4]; vector <int> G[N];
int idx, w[N], d[N], fa[18][N], pre[N], suf[N];
void dfs(int u) {
	pre[u] = ++idx;
	rep(i, 1, 17) fa[i][u] = fa[i-1][fa[i-1][u]];
	for(int v : G[u]) d[v] = d[u] + 1, fa[0][v] = u, dfs(v);
	suf[u] = idx;
}
int dis(int u, int v) {
	if(d[u] < d[v]) swap(u, v);
	if(pre[v] <= pre[u] && pre[u] <= suf[v]) return d[u] - d[v];
	int res = d[u] + d[v];
	per(i, 17, 0) {
		int nw = fa[i][u];
		if(nw && (pre[nw] > pre[v] || pre[v] > suf[nw])) u = nw;
	}
	return res - 2 * d[fa[0][u]];
}
void ins(int &u, int &v, int x) {
	if(!u || !x) return u = 0, void();
	int A = dis(u, v), B = dis(u, x), C = dis(v, x);
	if(A + B == C) return u = x, void();
	if(A + C == B) return v = x, void();
	if(B + C != A) u = 0;
}
void pushup(int o) {
	u[o] = u[o<<1], v[o] = v[o<<1];
	ins(u[o], v[o], u[o<<1|1]), ins(u[o], v[o], v[o<<1|1]);
}
void bld(int l, int r, int o) {
	if(l == r) u[o] = v[o] = ip[l];
	else bld(lch), bld(rch), pushup(o);
}
void upd(int p, int l, int r, int o) {
	if(l == r) return u[o] = v[o] = ip[l], void();
	if(p <= mid) upd(p, lch); else upd(p, rch);
	pushup(o);
}
int qry(int U, int V, int l, int r, int o) {
	if(l == r) return l;
	int uu = U, vv = V;
	if(!~uu) uu = u[o*2], vv = v[o*2];
	else ins(uu, vv, u[o*2]), ins(uu, vv, v[o*2]);
	return uu ? qry(uu, vv, rch) : qry(U, V, lch);
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) scanf("%d", &p[i]), ip[++p[i]] = i;
	int d;
	rep(i, 2, n) scanf("%d", &d), G[d].push_back(i);
	dfs(1), bld(1, n, 1);
	cin >> m;
	for(int op, a, b; m--;) {
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d%d", &a, &b), swap(p[a], p[b]), swap(ip[p[a]], ip[p[b]]);
			upd(p[a], 1, n, 1), upd(p[b], 1, n, 1);
		} else printf("%d\n", u[1] ? n : qry(-1, 0, 1, n, 1) - 1);
	}
	return 0; 
}