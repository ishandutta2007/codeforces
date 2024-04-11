#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, p;
	cin >> n >> k >> p;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> lvl(n);

	auto dfs = [&](int x, int p, const auto &self) -> void {
		for (int i : g[x]) {
			if (i != p) {
				lvl[i] = 1 + lvl[x];
				self(i, x, self);
			}
		}
	};

	dfs(0, -1, dfs);

	vector<int> v(n);
	iota(v.begin(), v.end(), 0);
	sort(v.begin(), v.end(), [&](int i, int j) {
		return lvl[i] > lvl[j];
	});

	auto f = [&](int score) -> long long {
		long long cur_ans = 0;
		int cur_lvl = lvl[v.front()];
		for (int i = 0; i < score; i++) {
			cur_ans += cur_lvl - lvl[v[i]];
		}
		long long ans = cur_ans;
		for (int i = score; i < n - 1; i++) {
			if (cur_lvl != lvl[v[i - score + 1]]) {
				cur_ans -= score - 1;
				cur_lvl = lvl[v[i - score + 1]];
			}
			cur_ans += cur_lvl - lvl[v[i]];
			ans = min(ans, cur_ans);
		}
		return ans;
	};

	int lo = 0, hi = min(k, n - 1);
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (f(mid) <= p)
			lo = mid;
		else hi = mid - 1;
	}

	cout << lo << '\n';
	return 0;
}