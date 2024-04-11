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

	long long ans = 0;
	vector<int> ptr(n);

	for (int rot = 0; rot < 2; rot++) {
		for (int i = 0; i < n; i++) {
			sort(g[i].begin(), g[i].end());
		}

		auto recurse = [&](const vector<int> &v, const auto &self) -> void {
			int empty = 0;
			map<int, vector<int>> mp;

			for (int i : v) {
				if (ptr[i] == int(g[i].size())) {
					ans += empty++;
				} else {
					mp[g[i][ptr[i]]].push_back(i);
					ptr[i]++;
				}
			}

			for (auto &p : mp) {
				self(p.second, self);
			}
		};

		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);
		fill(ptr.begin(), ptr.end(), 0);
		recurse(ind, recurse);

		if (rot == 0) {
			for (int i = 0; i < n; i++) {
				g[i].push_back(i);
				for (int j = int(g[i].size()) - 1; j > 0 && g[i][j] < g[i][j - 1]; j--) {
					swap(g[i][j], g[i][j - 1]);
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}