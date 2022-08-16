#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> b(n);
		for (auto &x : b) cin >> x, --x;

		vector<int> p(n);
		for (auto &x : p) cin >> x, --x;

		int r = -1;
		vector<vector<int>> g(n);
		for (int u = 0; u < n; u++) {
			if (b[u] == u) {
				r = u;
			} else {
				g[b[u]].push_back(u);
			}
		}

		vector<int> pos(n);
		for (int u = 0; u < n; u++) {
			pos[p[u]] = u;
		}

		vector<int> w(n);
		bool possible = true;

		auto dfs = [&](int u, int p, auto &&self) -> void {
			for (int v : g[u]) {
				w[v] = pos[v] - pos[u];
				possible &= w[v] > 0;
				self(v, u, self);
			}
		};
		dfs(r, -1, dfs);

		if (possible) {
			for (int u = 0; u < n; u++) {
				cout << w[u] << ' ';
			}
			cout << '\n';
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}