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

		vector<vector<int>> g(n);
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v, --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		int lg = 32 - __builtin_clz(n);

		vector<int> c(n);
		auto dfs = [&](int u, int p, auto &&self) -> void {
			for (int v : g[u]) {
				if (v != p) {
					c[v] = 1 ^ c[u];
					self(v, u, self);
				}
			}
		};
		dfs(0, -1, dfs);

		int ones = accumulate(c.begin(), c.end(), 0);
		int zeroes = n - ones;

		if (ones < zeroes) {
			swap(ones, zeroes);
			for (auto &x: c) {
				x ^= 1;
			}
		}

		vector<bool> chosen(lg);
		for (int i = 0; i < lg; i++) {
			if (zeroes >> i & 1) {
				chosen[i] = true;
			}
		}

		vector<int> p(n);
		for (int u = 0, i = 0; u < n; u++) {
			if (chosen[32 - __builtin_clz(u + 1) - 1]) {
				i = find(c.begin() + i, c.end(), 0) - c.begin();
				p[i] = u + 1;
				i++;
			}
		}

		for (int u = 0, i = 0; u < n; u++) {
			if (!chosen[32 - __builtin_clz(u + 1) - 1]) {
				i = find(c.begin() + i, c.end(), 1) - c.begin();
				p[i] = u + 1;
				i++;
			}
		}

		for (int i = 0; i < n; i++) {
			cout << p[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}