#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1, vector<int>());
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	int f;
	cin >> f;
	vector<int> h(f), cnt(n), d(n, -1);
	for (int i = 0; i < f; ++i) {
		cin >> h[i];
		--h[i];
		++cnt[h[i]];
	}
	int k;
	cin >> k;
	vector<int> p(k), masks(n);
	for (int i = 0; i < k; ++i) {
		cin >> p[i];
		--p[i];
		masks[h[p[i]]] |= 1 << i;
		--cnt[h[p[i]]];
	}
	vector<vector<int>> ok(n, vector<int>(1 << k));
	for (int i = 0; i < n; ++i)
		ok[i][0] = true;
	queue<int> que;
	que.emplace(0);
	d[0] = 0;
	while (!que.empty()) {
		int x = que.front(); que.pop();
		for (int y : adj[x]) {
			if (d[y] == -1) {
				d[y] = d[x] + 1;
				que.emplace(y);
			}
			if (d[y] == d[x] + 1) {
				for (int mask = 0; mask < (1 << k); ++mask) {
					ok[y][mask | masks[y]] |= ok[x][mask];
				}
			}
		}
	}
	bitset<128> lst;
	lst.set(0);
	for (int x = 0; x < n; ++x) {
		for (int i = 0; i < cnt[x]; ++i) {
			auto cur = lst;
			for (int s = 0; s < (1 << k); ++s) {
				for (int t = 0; t < (1 << k); ++t) {
					cur[s | t] = cur[s | t] || (ok[x][s] && lst[t]);
				}
			}
			lst = cur;
		}
	}
	int ans = 0;
	for (int mask = 0; mask < (1 << k); ++mask)
		if (lst[mask])
			ans = max(ans, __builtin_popcount(mask));
	cout << k - ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}