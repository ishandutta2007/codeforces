#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> g(n);
		for (int i = 0, u, v; i < m; i++) {
			cin >> u >> v;
			--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vector<bool> visited(n), chosen(n);
		queue<int> q;
		q.push(0);
		visited[0] = true;

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			bool f = true;
			for (int i : g[x]) {
				f &= !chosen[i];
				if (!visited[i]) {
					visited[i] = true;
					q.push(i);
				}
			}
			if (f) {
				chosen[x] = true;
			}
		}

		if (count(visited.begin(), visited.end(), false) != 0) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			cout << count(chosen.begin(), chosen.end(), true) << '\n';
			for (int i = 0; i < n; i++) if (chosen[i]) cout << i + 1 << ' '; cout << '\n';
		}
	}
	return 0;
}