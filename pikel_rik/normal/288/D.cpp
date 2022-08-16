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

	vector<int> sz(n), p(n);

	auto dfs = [&](int x, const auto &self) -> void {
		sz[x] = 1;
		for (int i : g[x]) {
			if (i != p[x]) {
				p[i] = x;
				self(i, self);
				sz[x] += sz[i];
			}
		}
	};

	p[0] = -1;
	dfs(0, dfs);

	long long ans = 0;

	auto choose2 = [&](long long n) -> long long {
		return (n * n - n) / 2;
	};

	for (int u = 0; u < n; u++) {
		long long sum = 0, sum_sq = 0, sum_ch = 0;

		for (int i : g[u]) {
			long long cur_sz = (i != p[u] ? sz[i] : n - sz[u]);
			sum += cur_sz;
			sum_sq += cur_sz * cur_sz;
			sum_ch += choose2(cur_sz);
		}

		for (int i : g[u]) {
			long long cur_sz = (i != p[u] ? sz[i] : n - sz[u]);
			sum -= cur_sz;
			sum_sq -= cur_sz * cur_sz;
			sum_ch -= choose2(cur_sz);

			long long pairwise = (sum * sum - sum_sq) / 2;
			ans += pairwise * choose2(cur_sz);
			ans += sum_ch * cur_sz;

			sum += cur_sz;
			sum_sq += cur_sz * cur_sz;
			sum_ch += choose2(cur_sz);
		}
	}

	cout << ans << '\n';
	return 0;
}