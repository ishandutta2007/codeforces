#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> p(n);
	vector<vector<int>> g(n);

	for (int i = 0; i < n; i++) {
		cin >> p[i];
		if (--p[i] != -1) {
			g[i].push_back(p[i]);
			g[p[i]].push_back(i);
		}
	}

	int timer = 0;
	vector<int> tin(n), tout(n);

	auto dfs = [&](int x, int p, const auto &dfs) -> void {
		tin[x] = timer++;
		for (int i : g[x]) {
			if (i == p) continue;
			dfs(i, x, dfs);
		}
		tout[x] = timer++;
	};

	int root = find(p.begin(), p.end(), -1) - p.begin();
	dfs(root, -1, dfs);

	auto f = [&](int u, int v) -> bool {
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	};

	bool ok = true;
	vector<int> next(n, -1), prev(n, -1);
	for (int i = 0, x, y; i < k; i++) {
		cin >> x >> y; --x; --y;
		ok &= next[x] == -1 && prev[y] == -1;
		ok &= x == p[y] || (!f(x, y) && !f(y, x));
		next[x] = y;
		prev[y] = x;
	}

	if (!ok) {
		cout << "0\n";
		return 0;
	}

	vector<int> par(n), r(n, 0), v(n);
	for (int i = 0; i < n; i++) {
		if (prev[i] == -1) {
			for (int x = i; x != -1; x = next[x]) {
				par[x] = i;
				r[i]++;
			}
		}
	}

	vector<bool> visited(n);
	vector<int> ans; ans.reserve(n);
	queue<int> q;

	q.push(root);
	visited[root] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (next[x] == -1 && prev[x] == -1) {
			ans.push_back(x);
			for (int i : g[x]) {
				if (!visited[i]) {
					visited[i] = true;
					q.push(i);
				}
			}
		} else if (v[par[x]] != r[par[x]]) {
			v[par[x]]++;
			for (int i : g[x]) {
				if (!visited[i] && par[i] == par[x]) {
					visited[i] = true;
					q.push(i);
				}
			}
			if (v[par[x]] == r[par[x]]) {
				for (int i = par[x]; i != -1; i = next[i]) {
					ans.push_back(i);
					q.push(i);
				}
			}
		} else if (v[par[x]] == r[par[x]]) {
			for (int i : g[x]) {
				if (!visited[i]) {
					visited[i] = true;
					q.push(i);
				}
			}
		}
	}

	if (ans.size() != n) {
		cout << 0 << '\n';
	} else {
		for (int i : ans) cout << i + 1 << ' ';
		cout << '\n';
	}
	return 0;
}