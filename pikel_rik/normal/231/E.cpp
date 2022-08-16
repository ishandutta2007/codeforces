#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, m, c, p[N], id[N], a[N], two[N];
vector<int> g[N];
vector<vector<int>> cycles;

bool in_cycle[N];
bool visited[N];

void dfs(int x) {
	visited[x] = true;
	for (int i : g[x]) {
		if (i == p[x]) continue;
		if (!visited[i]) {
			p[i] = x;
			dfs(i);
		} else if (!in_cycle[i]) {
			cycles.emplace_back();
			int ptr = x;
			while (ptr != p[i]) {
				in_cycle[ptr] = true;
				cycles.back().push_back(ptr);
				ptr = p[ptr];
			}
		}
	}
}

int T, tin[N], tout[N], d[N], up[N][17], table[N][17];
vector<int> new_g[N];

void dfs(int x, int par) {
	tin[x] = T++;
	up[x][0] = par;
	for (int i = 1; i < 17; i++) up[x][i] = up[up[x][i - 1]][i - 1];

	table[x][0] = a[par];
	for (int i = 1; i < 17; i++) table[x][i] = table[x][i - 1] + table[up[x][i - 1]][i - 1];

	for (int i : new_g[x]) {
		if (i == par) continue;
		d[i] = 1 + d[x];
		dfs(i, x);
	}
	tout[x] = T++;
}

inline bool f(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	for (int i = 16; i >= 0; i--) {
		if (up[u][i] && !f(up[u][i], v)) {
			u = up[u][i];
		}
	}
	return up[u][0];
}

int queryHelper(int u, int l) {
	int ans = 0;
	for (int i = 0; i < 17; i++) {
		if ((1 << i) & l) {
			ans += table[u][i];
			u = up[u][i];
		}
	}
	return ans;
}

int query(int u, int v) {
	if (f(u, v)) {
		return a[v] + queryHelper(v, d[v] - d[u]);
	} else if (f(v, u)) {
		return a[u] + queryHelper(u, d[u] - d[v]);
	}
	int l = lca(u, v);
	return a[u] + a[v] + queryHelper(u, d[u] - d[l]) + queryHelper(v, d[v] - d[l] - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	two[0] = 1;
	for (int i = 1; i < N; i++) two[i] = 2 * two[i - 1] % mod;

	cin >> n >> m;
	vector<pair<int, int>> edges; edges.reserve(m);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		edges.emplace_back(u, v);
	}

	dfs(1);

	int cur = 0;
	for (auto &cycle : cycles) {
		++cur;
		for (int v : cycle) {
			id[v] = cur;
		}
		a[cur] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (!in_cycle[i]) {
			id[i] = ++cur;
		}
	}

	for (auto &cycle : cycles) {
		for (int v : cycle) {
			for (int i : g[v]) {
				if (id[i] == id[v]) continue;
				if (!a[id[i]]) {
					new_g[id[v]].push_back(id[i]);
					new_g[id[i]].push_back(id[v]);
				} else {
					new_g[id[v]].push_back(id[i]);
				}
			}
		}
	}

	for (auto&[u, v] : edges) {
		if (a[id[u]] || a[id[v]]) continue;
		new_g[id[u]].push_back(id[v]);
		new_g[id[v]].push_back(id[u]);
	}

	dfs(1, 0);

	int q;
	cin >> q;

	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << two[query(id[u], id[v])] << '\n';
	}
	return 0;
}