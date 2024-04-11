#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> fib = {1, 1};
	for (int a = 1, b = 1; a + b <= n;) {
		fib.push_back(a + b);
		tie(a, b) = make_pair(b, a + b);
	}

	vector<bool> is_fib(n + 1);
	for (int f : fib) {
		is_fib[f] = true;
	}

	if (!is_fib[n]) {
		cout << "NO\n";
		return 0;
	}

	vector<vector<int>> g(n);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> sz(n);
	auto is_fib_tree = [&](int n, int root, const auto &fself) -> bool {
		if (n == 1)
			return true;

		pair<int, int> split_edge(-1, -1);
		auto dfs = [&](int x, int p, const auto &self) -> void {
			sz[x] = 1;
			for (int i : g[x]) {
				if (i != p) {
					self(i, x, self);
					sz[x] += sz[i];
					if (is_fib[sz[i]] && is_fib[n - sz[i]]) {
						split_edge = make_pair(x, i);
					}
				}
			}
		};

		dfs(root, -1, dfs);
		auto [u, v] = split_edge;
		if (u == -1)
			return false;
		g[u].erase(find(g[u].begin(), g[u].end(), v));
		g[v].erase(find(g[v].begin(), g[v].end(), u));
		return fself(n - sz[v], u, fself) && fself(sz[v], v, fself);
	};

	cout << (is_fib_tree(n, 0, is_fib_tree) ? "YES" : "NO") << '\n';
	return 0;
}