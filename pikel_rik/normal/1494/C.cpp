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

		vector<int> a(n), b(m);
		for (auto &x : a) cin >> x;
		for (auto &x : b) cin >> x;

		int ans = 0;
		for (int rot = 0; rot < 2; rot++) {
			int zero_a = upper_bound(a.begin(), a.end(), 0) - a.begin();
			int zero_b = upper_bound(b.begin(), b.end(), 0) - b.begin();

			int cur_pos = 0;
			for (int i = zero_b; i < m; i++) {
				cur_pos += binary_search(a.begin(), a.end(), b[i]);
			}

			int best_pos = cur_pos;
			for (int i = zero_b; i < m; i++) {
				cur_pos -= binary_search(a.begin(), a.end(), b[i]);
				int there = (upper_bound(a.begin(), a.end(), b[i]) - a.begin()) - zero_a;
				int furthest = lower_bound(b.begin(), b.end(), b[i] - there + 1) - b.begin();
				best_pos = max(best_pos, cur_pos + i - furthest + 1);
			}

			ans += best_pos;
			for (auto &x : a) x = -x;
			for (auto &x : b) x = -x;
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
		}
		cout << ans << '\n';
	}
	return 0;
}