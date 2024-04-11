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

		vector<int> w(n);
		for (int i = 0; i < n; i++) cin >> w[i];

		vector<vector<int>> g(n);
		for (int i = 0, u, v; i < n - 1; i++) {
			cin >> u >> v, --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vector<int> v; v.reserve(n);
		for (int i = 0; i < n; i++) {
			if (g[i].size() > 1) {
				v.push_back(i);
			}
		}

		sort(v.begin(), v.end(), [&](int x, int y) {
			return w[x] > w[y];
		});

		long long cur = accumulate(w.begin(), w.end(), 0ll);
		cout << cur << ' ';

		int colors = 2;
		for (int u : v) {
			for (int i = 0; i + 1 < (int)g[u].size() && colors < n; i++) {
				cur += w[u];
				cout << cur << ' ';
				colors++;
			}
		}
		cout << '\n';
	}
	return 0;
}