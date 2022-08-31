#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> g(n);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int mx = 0;
	for (int u = 0; u < n; u++) {
		mx = max(mx, (int) g[u].size());
	}

	vector<pair<int, int>> ans;

	int cur_time = 0;
	vector<int> first_time(n, -1), last_time(n, -1);

	vector<int> left(n);

	auto dfs = [&](int u, int p, const auto &self) -> void {
		ans.emplace_back(u, cur_time);
		left[u] = (int) g[u].size() - 1;
		first_time[u] = last_time[u] = cur_time;
		for (int v : g[u]) {
			if (v != p) {
				if (cur_time == mx) {
					cur_time = first_time[u] - left[u] - 1;
					ans.emplace_back(u, cur_time);
					last_time[u] = cur_time;
				}
				cur_time += 1;
				self(v, u, self);
			}
		}
		if (p != -1) {
			if (cur_time != first_time[u] - 1) {
				cur_time = first_time[u] - 1;
				ans.emplace_back(u, cur_time);
			}
			cur_time += 1;
			ans.emplace_back(p, cur_time);
			left[p] -= 1;
		}
	};

	dfs(0, -1, dfs);

	cout << (int) ans.size() << '\n';
	for (auto &[u, t] : ans) {
		cout << u + 1 << ' ' << t << '\n';
	}
	return 0;
}