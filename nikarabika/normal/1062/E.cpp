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

const int maxn = 1e5 + 10,
	  maxl = 20;
int h[maxn],
	st[maxn],
	par[maxn][maxl],
	n, q;
pii seg[maxn << 2];
vector<int> adj[maxn];

void dfs(int u, int p = -1) {
	static int tim = 0;
	st[u] = tim++;
	par[u][0] = p;
	for (int i = 1; i < maxl; i++)
		if (~par[u][i - 1])
			par[u][i] = par[par[u][i - 1]][i - 1];
	for (auto v : adj[u]) {
		h[v] = h[u] + 1;
		dfs(v, u);
	}
}

int lca(int u, int v) {
	if (h[u] < h[v])
		swap(u, v);
	for (int i = 0; h[u] - h[v]; i++)
		if (((h[u] - h[v]) >> i) & 1)
			u = par[u][i];
	if (u == v)
		return u;
	for (int i = maxl - 1; i >= 0; i--)
		if (par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

pii operator+(pii l, pii r) {
	//cout << "# "<< l.L << ' ' << l.R << ' ' << r.L << ' ' << r.R << endl;
	pii res;
	res.L = st[l.L] < st[r.L] ? l.L : r.L;
	res.R = st[l.R] < st[r.R] ? r.R : l.R;
	return res;
}

pii get(int st, int en, int l = 0, int r = n, int id = 1) {
	if (st >= r or en <= l)
		return MP(n, n + 1);
	if (st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	return get(st, en, l, mid, id << 1 | 0)
		+ get(st, en, mid, r, id << 1 | 1);
}


pii build(int l = 0, int r = n, int id = 1) {
	if (r - l == 1)
		return seg[id] = pii(l, l);
	int mid = (l + r) >> 1;
	return seg[id] = build(l, mid, id << 1 | 0)
		+ build(mid, r, id << 1 | 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	st[n] = 1e8;
	st[n + 1] = -1e8;
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x, x--;
		adj[x].PB(i);
	}
	dfs(0);
	build();
	while (q--) {
		int fi, se;
		cin >> fi >> se;
		fi--;
		pii node = get(fi, se);
		pii node2 = get(fi, node.L) + get(node.L + 1, se);
		pii node3 = get(fi, node.R) + get(node.R + 1, se);
		int p2 = lca(node2.L, node2.R);
		int p3 = lca(node3.L, node3.R);
		if (h[p2] > h[p3])
			cout << node.L + 1 << ' ' << h[p2] << '\n';
		else
			cout << node.R + 1 << ' ' << h[p3] << '\n';
	}
	return 0;
}