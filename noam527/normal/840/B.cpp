#include <iostream>
#include <vector>
using namespace std;

struct edge {
	int v, i;
	edge(int v = 0, int i = 0) : v(v), i(i) {};
};

int n, m, d[300000], at = -1, c = 0;
vector<int> ans, v(300000, 0);
vector<vector<edge>> g;

void dfs(int u) {
	v[u] = 1;
	for (auto &i : g[u])
		if (!v[i.v]) {
			dfs(i.v);
			if (d[i.v] == 1) {
				ans.push_back(i.i), d[i.v] = 0;
				if (d[u] != -1) d[u] ^= 1;
			}
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		if (d[i] == 1) c++;
		if (d[i] == -1) at = i;
	}
	if (at == -1) {
		if (c & 1) return cout << -1 << endl, 0;
		at = 0;
	}

	g.resize(n);
	for (int i = 0, u, v; i < m; i++)
		cin >> u >> v, g[--u].push_back(edge(--v, i + 1)), g[v].push_back(edge(u, i + 1));
	dfs(at);
	cout << ans.size() << endl;
	for (auto i : ans) cout << i << endl;
}