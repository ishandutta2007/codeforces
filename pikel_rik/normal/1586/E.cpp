#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int timer = 0;
	vector<int> p(n, -1), tin(n, -1), tout(n);

	auto dfs = [&](int u, auto &&self) -> void {
		tin[u] = timer++;
		for (int v : g[u]) {
			if (tin[v] == -1) {
				p[v] = u;
				self(v, self);
			}
		}
		tout[u] = timer++;
	};

	dfs(0, dfs);

	auto is_anc = [&](int u, int v) -> bool {
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	};

	vector<int> odd(n);

	int q;
	cin >> q;

	vector<pair<int, int>> paths(q);
	for (auto &[a, b] : paths) {
		cin >> a >> b, --a, --b;
		odd[a] ^= 1, odd[b] ^= 1;
	}

	int sum = accumulate(odd.begin(), odd.end(), 0);
	if (sum > 0) {
		cout << "NO\n";
		cout << sum / 2 << '\n';
		return 0;
	}

	cout << "YES\n";
	for (auto [a, b] : paths) {
		vector<int> path_a_l, path_b_l;

		int u;
		for (u = a;; u = p[u]) {
			path_a_l.push_back(u);
			if (is_anc(u, b)) {
				break;
			}
		}
		for (u = b; !is_anc(u, a); u = p[u]) {
			path_b_l.push_back(u);
		}

		cout << path_a_l.size() + path_b_l.size() << '\n';
		for (int v : path_a_l) {
			cout << v + 1 << ' ';
		}
		reverse(path_b_l.begin(), path_b_l.end());
		for (int v : path_b_l) {
			cout << v + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}