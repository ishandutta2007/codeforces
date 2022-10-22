#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define fi first
#define se second
#define pb push_back

using namespace std;
const int N = 1e5 + 5, M = 1e7, NUM = 664580, P = 1e9 + 7;
typedef pair <int, int> pii;
typedef long long ll;
ll Pow(ll a, int n, ll r = 1) {
	for(; n; n >>= 1, a = a * a % P)
	if(n & 1) r = r * a % P;
	return r;
}
int cnt, v[M+5], prm[NUM];
vector <int> G[N]; vector <pii> id[NUM], node[NUM];
int n, idx, d[N], dfn[N], suf[N], fa[17][N], c[N];
int q, x[N], y[N], z[N], tmp[N]; ll ans[N];
void add(int i, int v) { for(; i <= n; i += i & -i) c[i] += v; }
int qry(int i, int r = 0) { for(; i; i &= i - 1) r += c[i]; return r; }
void dfs(int u) {
	dfn[u] = ++idx;
	rep(i, 1, 16) fa[i][u] = fa[i-1][fa[i-1][u]];
	for(int v : G[u]) if(v ^ fa[0][u]) d[v] = d[fa[0][v] = u] + 1, dfs(v);
	suf[u] = idx + 1;
}
int lca(int u, int v) {
	if(d[u] < d[v]) swap(u, v);
	per(i, 16, 0) if(d[u] - (1 << i) >= d[v]) u = fa[i][u];
	if(u == v) return u;
	per(i, 16, 0) if(fa[i][u] ^ fa[i][v]) u = fa[i][u], v = fa[i][v];
	return fa[0][u];
}
void upd(int u, int v) { add(dfn[u], v), add(suf[u], -v); }
int calc(int i) { return qry(dfn[x[i]]) + qry(dfn[y[i]]) - qry(dfn[z[i]]) - qry(dfn[fa[0][z[i]]]); }
void ins(vector <pii> A[], int x, int i) {
	while(v[x]) {
		int p = v[x], t = 0;
		while(v[x] == p) x /= prm[p], t++;
		A[p].pb(make_pair(t, i));
	}
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	rep(i, 2, M) {
		if(!v[i]) prm[v[i] = ++cnt] = i;
		for(int j = 1; j <= v[i] && i * prm[j] <= M; j++) v[i*prm[j]] = j;
	}
	cin >> n;
	int u, v;
	rep(i, 2, n) scanf("%d%d", &u, &v), G[u].pb(v), G[v].pb(u);
	dfs(1);
	rep(i, 1, n) scanf("%d", &u), ins(node, u, i);
	cin >> q;
	rep(i, 1, q) scanf("%d%d%d", &x[i], &y[i], &u), ins(id, u, i), ans[i] = 1, z[i] = lca(x[i], y[i]);
	rep(i, 1, cnt) {
		sort(node[i].begin(), node[i].end());
		sort(id[i].begin(), id[i].end());
		int j = 0, sz = node[i].size();
		for(pii& u : id[i]) {
			while(j < sz && node[i][j].fi <= u.fi) upd(node[i][j].se, node[i][j].fi), j++;
			tmp[u.se] = calc(u.se);
		}
		For(k, 0, j) upd(node[i][k].se, -node[i][k].fi);
		sort(node[i].rbegin(), node[i].rend());
		sort(id[i].rbegin(), id[i].rend());
		j = 0;
		for(pii& u : id[i]) {
			while(j < sz && node[i][j].fi > u.fi) upd(node[i][j].se, 1), j++;
			ans[u.se] = ans[u.se] * Pow(prm[i], tmp[u.se] + calc(u.se) * u.fi) % P;
		}
		For(k, 0, j) upd(node[i][k].se, -1);
	}
	rep(i, 1, q) printf("%lld\n", ans[i]);
	return 0;
}