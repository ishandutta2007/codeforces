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

		vector<vector<int>> g(n);
		for (int i = 0, u, v; i < n - 1; i++) {
			cin >> u >> v, --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vector<int> lvl(n, -1), deg(n);
		queue<int> q;

		for (int u = 0; u < n; u++) {
			deg[u] = g[u].size();
			if (deg[u] == 1) {
				lvl[u] = 1;
				q.push(u);
			}
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : g[u]) {
				if (lvl[v] == -1) {
					deg[v] -= 1;
					if (deg[v] == 1) {
						lvl[v] = 1 + lvl[u];
						q.push(v);
					}
				}
			}
		}

		int ans = 0;
		for (int u = 0; u < n; u++) {
			ans += lvl[u] > k;
		}

		cout << ans << '\n';
	}
	return 0;
}