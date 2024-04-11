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

		vector<long long> current(n), target(n);
		for (auto &x : current) cin >> x;
		for (auto &x : target) cin >> x;

		long long current_sum = accumulate(current.begin(), current.end(), 0ll);
		long long target_sum = accumulate(target.begin(), target.end(), 0ll);

		vector<vector<int>> g(n);
		for (int i = 0, u, v; i < m; i++) {
			cin >> u >> v, --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		if ((current_sum - target_sum) % 2) {
			cout << "NO\n";
			continue;
		}

		vector<int> d(n, -1);
		bool odd_cycle = false;

		auto dfs = [&](int x, const auto &self) -> void {
			for (int i : g[x]) {
				if (d[i] == -1) {
					d[i] = 1 + d[x];
					self(i, self);
					long long diff = target[i] - current[i];
					current[i] += diff;
					current[x] += diff;
				} else {
					odd_cycle |= d[x] % 2 == d[i] % 2;
				}
			}
		};

		d[0] = 0;
		dfs(0, dfs);

		if (current[0] == target[0] || odd_cycle) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}