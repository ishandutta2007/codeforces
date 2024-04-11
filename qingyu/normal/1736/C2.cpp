#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 50;
int64_t a[N], p[N], v[N], f[N], g[N], sum[N], sf[N], ans[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i] = min(f[i - 1] + 1, a[i]);
		sum[i] = sum[i - 1] + a[i];
		sf[i] = sf[i - 1] + f[i];
	}
	int q;
	cin >> q;
	vector<pair<int64_t, int>> queries, positions;
	for (int i = 1; i <= q; ++i) {
		cin >> p[i] >> v[i];
		int64_t new_dp = min(f[p[i] - 1] + 1, v[i]);
		queries.emplace_back(new_dp - p[i], i);
	}
	for (int i = 1; i <= n; ++i) {
		queries.emplace_back(a[i] - i, -i);
	}
	sort(queries.begin(), queries.end());
	set<int> cand;
	int cur = 0;
	auto s2 = [&](int64_t x) {
		return x * (x + 1) / 2;
	};
	for (auto [x, id] : queries) {
		if (id < 0) {
			id = -id;
			auto it = cand.lower_bound(id);
			int q = (it == cand.end() ? n + 1 : *it);
			cand.emplace(id);
			g[id] = g[q] + s2(q - id) + (a[id] - 1) * (q - id);
		}
		else {
			int64_t p = ::p[id], v = ::v[id];
			while (cur < positions.size() && positions[cur].first <= x) {
				cand.emplace(positions[cur].second);
				++cur;
			}
			int64_t new_dp = min(f[p - 1] + 1, (int64_t)v);
			auto it = cand.upper_bound(p);
			int q = (it == cand.end() ? n + 1 : *it);
			ans[id] = sf[p - 1] + g[q] + s2(q - p) + (q - p) * (new_dp - 1);
		}
	}
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << '\n';
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}