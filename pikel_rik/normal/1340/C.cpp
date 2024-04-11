#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> d(m);
	for (auto &x : d) cin >> x;

	int g, r;
	cin >> g >> r;

	sort(d.begin(), d.end());

	constexpr int inf = (int) 1e9;
	vector<vector<int>> dist(m, vector<int>(g, inf));

	deque<pair<int, int>> q;
	q.emplace_back(0, 0), dist[0][0] = 0;

	while (!q.empty()) {
		auto [i, t] = q.front();
		q.pop_front();

		for (int j : {i - 1, i + 1}) {
			if (j < 0 || m <= j) {
				continue;
			}
			if (t + abs(d[i] - d[j]) < g) {
				int new_t = t + abs(d[i] - d[j]);
				if (dist[i][t] < dist[j][new_t]) {
					dist[j][new_t] = dist[i][t];
					q.emplace_front(j, new_t);
				}
			} else if (t + abs(d[i] - d[j]) == g) {
				if (dist[i][t] + 1 < dist[j][0]) {
					dist[j][0] = 1 + dist[i][t];
					q.emplace_back(j, 0);
				}
			}
		}
	}

	int ans = inf;
	for (int t = 0; t < g; t++) {
		if (dist[m - 1][t] == inf) {
			continue;
		}
		if (t > 0) {
			ans = min(ans, dist[m - 1][t] * (g + r) + t);
		} else {
			ans = min(ans, (dist[m - 1][t] - 1) * (g + r) + g);
		}
	}
	cout << (ans == inf ? -1 : ans) << '\n';
	return 0;
}