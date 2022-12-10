//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2e5 + 10,
	  maxl = 20;
int stim[maxn],
	ftim[maxn],
	seg[maxl][maxn],
	go[maxn][maxl],
	par[maxn][maxl],
	h[maxn],
	n, m, q;
vector<pii> routes;
vector<int> adj[maxn];

void dfs_st(int u = 0) {
	static int tim = 0;
	stim[u] = tim++;
	for (auto v : adj[u])
		dfs_st(v);
	ftim[u] = tim;
}

pii get_moves(int u, int p) {
	int cnt = 0;
	for (int i = maxl - 1; i >= 0; i--)
		if (h[go[u][i]] > h[p])
			u = go[u][i], cnt += 1 << i;
	return MP(cnt, u);
}

int lca(int u, int v) {
	if (h[u] < h[v])
		swap(u, v);
	for (int i = 0; h[u] ^ h[v]; i++)
		if (((h[u] - h[v]) >> i) & 1)
			u = par[u][i];
	if (u == v)
		return u;
	for (int i = maxl - 1; i >= 0; i--)
		if (par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

void build(int l = 0, int r = m, int id = 0) {
	if (r - l == 1) {
		seg[id][l] = routes[l].R;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id + 1);
	build(mid, r, id + 1);
	merge(seg[id + 1] + l, seg[id + 1] + mid,
			seg[id + 1] + mid, seg[id + 1] + r,
			seg[id] + l);
}

int get(int val, int st, int en, int l = 0, int r = m, int id = 0) {
	if (st >= r or en <= l)
		return 0;
	if (st <= l and r <= en)
		return lower_bound(seg[id] + l, seg[id] + r, val) - (seg[id] + l);
	int mid = (l + r) >> 1;
	return get(val, st, en, l, mid, id + 1)
		+ get(val, st, en, mid, r, id + 1);
}

int seget(int st, int en, int l, int r) {
	int st_pos = lower_bound(all(routes), MP(st, 0)) - routes.begin();
	int en_pos = lower_bound(all(routes), MP(en, 0)) - routes.begin();
	return get(l, st_pos, en_pos) - get(r, st_pos, en_pos);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(par, -1, sizeof par);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> par[i][0];
		adj[--par[i][0]].PB(i);
		h[i] = h[par[i][0]] + 1;
		go[i][0] = i;
		for (int j = 1; j < maxl; j++) {
			if (~par[i][j - 1])
				par[i][j] = par[par[i][j - 1]][j - 1];
			go[i][j] = i;
		}
	}
	dfs_st();
	cin >> m;
	for (int i = 0; i < m; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		if (stim[fi] > stim[se])
			swap(fi, se);
		int p = lca(fi, se);
		routes.PB(MP(stim[fi], stim[se]));
		if (h[p] < h[go[fi][0]])
			go[fi][0] = p;
		if (h[p] < h[go[se][0]])
			go[se][0] = p;
	}
	for (int i = n - 1; i > 0; i--)
		if (h[go[i][0]] < h[go[par[i][0]][0]])
			go[par[i][0]][0] = go[i][0];
	for (int i = 0; i < n; i++)
		for (int j = 1; j < maxl; j++)
			go[i][j] = go[go[i][j - 1]][j - 1];
	sort(all(routes));
	build();
	cin >> q;
	for (int i = 0; i < q; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		if (stim[fi] > stim[se])
			swap(fi, se);
		int p = lca(fi, se);
		pii m1 = get_moves(fi, p),
			m2 = get_moves(se, p);
		if (max(m1.L, m2.L) > maxn) {
			cout << -1 << '\n';
			continue;
		}
		int u = m1.R,
			v = m2.R;
		if (fi == p)
			cout << m2.L + 1 << '\n';
		else if (seget(stim[u], ftim[u], stim[v], ftim[v]))
			cout << m1.L + m2.L + 1 << '\n';
		else
			cout << m1.L + m2.L + 2 << '\n';
	}
	return 0;
}