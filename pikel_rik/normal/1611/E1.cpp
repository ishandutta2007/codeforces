#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> x(k);
		for (int i = 0; i < k; i++) {
			cin >> x[i], --x[i];
		}

		vector<vector<int>> g(n);
		for (int i = 0, u, v; i < n - 1; i++) {
			cin >> u >> v, --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vector<int> time(n, n);
		for (int i = 0; i < k; i++) {
			time[x[i]] = 0;
		}

		auto dfs = [&](int u, int p, int d, auto &&self) -> bool {
			bool can_child_win = false;
			if (p != -1 && g[u].size() == 1) {
				can_child_win = true;
			}
			for (int v : g[u]) {
				if (v != p) {
					can_child_win |= self(v, u, d + 1, self);
					time[u] = min(time[u], 1 + time[v]);
				}
			}
			return d < time[u] && can_child_win;
		};

		cout << (dfs(0, -1, 0, dfs) ? "YES" : "NO") << '\n';
	}
	return 0;
}