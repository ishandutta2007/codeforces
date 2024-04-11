#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct Edge {
	int u, v, w, c, ind;
	int o(int x) {
		return u ^ x ? u : v;
	}
} e[200000];

int n, m, S, par[200000], dep[200000], anc[200000][18], mx[200000][18];
ll ans = 1e18, base;
vector<int> adj[200000];

int find(int i) {
	return i ^ par[i] ? par[i] = find(par[i]) : i;
}

bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b)
		return 0;
	par[b] = a;
	return 1;
}

int comb(int a, int b) {
	if (a == -1)
		return b;
	if (b == -1)
		return a;
	return e[a].w >= e[b].w ? a : b;
}

void dfs(int u = 0, int p = -1) {
	for (int i = 1; i < 18; ++i) {
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
		mx[u][i] = comb(mx[u][i - 1], mx[anc[u][i - 1]][i - 1]);
	}
	for (int x : adj[u]) {
		int v = e[x].o(u);
		if (p ^ v) {
			dep[v] = dep[u] + 1;
			anc[v][0] = u;
			mx[v][0] = x;
			dfs(v, u);
		}
	}
}

int lca(int a, int b) {
	if (dep[a] > dep[b])
		swap(a, b);
	int big = -1;
	for (int i = 17; ~i; --i)
		if (dep[b] - (1 << i) >= dep[a])
			big = comb(big, mx[b][i]), b = anc[b][i];
	if (a == b)
		return big;
	for (int i = 17; ~i; --i)
		if (anc[a][i] ^ anc[b][i])
			big = comb(big, comb(mx[a][i], mx[b][i])), a = anc[a][i], b = anc[b][i];
	return comb(big, comb(mx[a][0], mx[b][0]));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	iota(par, par + n, 0);
	for (int i = 0; i < m; ++i)
		cin >> e[i].w, e[i].ind = i;
	for (int i = 0; i < m; ++i)
		cin >> e[i].c;
	for (int i = 0; i < m; ++i)
		cin >> e[i].u >> e[i].v, --e[i].u, --e[i].v;
	cin >> S;
	sort(e, e + m, [](const Edge& a, const Edge& b) {
		return a.w < b.w;
	});
	vector<int> road;
	for (int i = 0; i < m; ++i) {
		if (merge(e[i].u, e[i].v)) {
			base += e[i].w;
			adj[e[i].u].push_back(i);
			adj[e[i].v].push_back(i);
			road.push_back(i);
		}
	}
	assert(road.size() == n - 1);
	mx[0][0] = -1;
	dfs();
	//for (int i = 0; i < n; ++i) {
	//	cerr << dep[i] << " " << anc[i][0] << " " << mx[i][0] << "\n";
	//}
	pair<int, int> best = {-1, -1};
	for (int i = 0; i < m; ++i) {
		int big = lca(e[i].u, e[i].v);
		assert(big != -1);
		int cur = e[i].w - S / e[i].c;
		if (cur - e[big].w + base < ans) {
			ans = cur - e[big].w + base;
			best = {i, big};
		}
	}
	assert(best.first != -1);
	//cout << best.first << " " << best.second << "\n";
	cout << ans << "\n";
	cout << e[best.first].ind + 1 << " " << e[best.first].w - S / e[best.first].c << "\n";
	for (int i : road)
		if (i ^ best.second)
			cout << e[i].ind + 1 << " " << e[i].w << "\n";
	return 0;
}