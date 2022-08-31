#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	struct edge { int u, v, w; };

	int n, m;
	cin >> n >> m;

	vector<edge> e(m);
	vector<vector<int>> g(n);

	for (int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		g[e[i].u].push_back(i);
	}

	constexpr long long inf = (long long)1e10;

	vector<long long> d(n, inf), go(n);
	vector<bool> visited(n);

	for (int s = 0; s < n; s++) {
		fill(d.begin(), d.end(), inf);
		fill(visited.begin(), visited.end(), false);

		d[s] = 0;

		for (int iter = 0; iter < n; iter++) {
			int x = -1;
			for (int j = 0; j < n; j++) {
				go[j] = inf;
				if (!visited[j] && (x == -1 || d[j] < d[x])) {
					x = j;
				}
			}

			visited[x] = true;

			int inc = d[x] % n;

			for (int i : g[x]) {
				int v = e[i].v + inc;
				if (v >= n) v -= n;
				go[v] = min(go[v], (long long)e[i].w);
				go[0] = min(go[0], (long long)e[i].w + (v == 0 ? 0 : n - v));
			}

			long long mn = inf;
			for (int i = 0; i < n; i++) {
				mn = min(mn, go[i]);
				d[i] = min(d[i], d[x] + mn);
				mn += 1;
			}
		}

		for (int i = 0; i < n; i++) {
			cout << d[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}