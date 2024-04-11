#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<pair<int, int>> events;
	for (int i = 1, l, r; i <= n; i++) {
		cin >> l >> r;
		events.emplace_back(l, i);
		events.emplace_back(r, -i);
	}

	sort(events.begin(), events.end(), [&](const pair<int, int> &x, const pair<int, int> &y) {
		return x.first < y.first || (x.first == y.first && x.second > y.second);
	});

	events.emplace_back(events.back().first + 1, 0);

	vector<int> cur_s(k, -1), action(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		if (events[i].second > 0) {
			int j = find(cur_s.begin(), cur_s.end(), -1) - cur_s.begin();
			cur_s[j] = events[i].second;
			action[i] = j;
		} else {
			int j = find(cur_s.begin(), cur_s.end(), -events[i].second) - cur_s.begin();
			cur_s[j] = -1;
			action[i] = j;
		}
	}

	vector<vector<int>> dp(2 * n + 1, vector<int>(1 << k));
	fill(dp[2 * n].begin(), dp[2 * n].end(), 0);

	for (int i = 2 * n - 1; i >= 0; i--) {
		for (int mask = 0; mask < (1 << k); mask++) {
			if (events[i].second > 0) {
				if (mask >> action[i] & 1) {
					continue;
				}
				bool add = events[i].first == events[i + 1].first && events[i + 1].second < 0;
				for (int new_mask : {mask, mask | (1 << action[i])}) {
					if (events[i + 1].first > events[i].first && __builtin_popcount(new_mask) % 2 != 0) {
						if (events[i + 1].second > 0) {
							dp[i][mask] = max(dp[i][mask], events[i + 1].first - events[i].first + dp[i + 1][new_mask]);
						} else if (events[i + 1].second < 0) {
							dp[i][mask] = max(dp[i][mask], events[i + 1].first - events[i].first + 1 + dp[i + 1][new_mask]);
						}
					} else if (add && __builtin_popcount(new_mask) % 2 != 0) {
						dp[i][mask] = max(dp[i][mask], 1 + dp[i + 1][new_mask]);
					} else {
						dp[i][mask] = max(dp[i][mask], dp[i + 1][new_mask]);
					}
				}
			} else {
				int new_mask = mask & ~(1 << action[i]);
				dp[i][mask] = dp[i + 1][new_mask];
				if (events[i + 1].first > events[i].first && __builtin_popcount(new_mask) % 2 != 0) {
					if (events[i + 1].second > 0) {
						dp[i][mask] += events[i + 1].first - events[i].first - 1;
					} else if (events[i + 1].second < 0) {
						dp[i][mask] += events[i + 1].first - events[i].first;
					}
				}
			}
		}
	}

	cout << dp[0][0] << '\n';
//	for (int i = 0; i < 2 * n; i++) {
//		for (int mask = 0; mask < (1 << k); mask++) {
//			cout << i << ' ' << bitset<3>(mask) << ' ' << dp[i][mask] << '\n';
//		}
//	}
	return 0;
}