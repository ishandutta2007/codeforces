#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> w(n);
	for (auto &x : w) cin >> x;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int s;
	cin >> s, --s;

	vector<bool> marked(n);
	vector<int> ancestors, d(n, -1);
	auto dfs = [&](int u, int p, const auto &self) -> void {
		ancestors.push_back(u);
		for (int v : g[u]) {
			if (d[v] == -1) {
				d[v] = 1 + d[u];
				self(v, u, self);
			} else if (v != p && d[v] < d[u]) {
				while (!ancestors.empty()) {
					marked[ancestors.back()] = true;
					ancestors.pop_back();
				}
			}
		}
		if (!ancestors.empty() && ancestors.back() == u) {
			ancestors.pop_back();
		}
	};

	d[s] = 0, marked[s] = true;
	dfs(s, -1, dfs);

	long long ans = 0;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (marked[i]) {
			ans += w[i];
			q.push(i);
		}
	}

	vector<long long> dp(n);
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : g[u]) {
			if (!marked[v]) {
				dp[v] = w[v] + dp[u];
				marked[v] = true, q.push(v);
			}
		}
	}

	ans += *max_element(dp.begin(), dp.end());
	cout << ans << '\n';
	return 0;
}