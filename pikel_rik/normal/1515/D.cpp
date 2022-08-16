#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, l, r;
		cin >> n >> l >> r;

		vector<int> c(n);
		for (auto &x : c) cin >> x, --x;

		vector<pair<int, int>> cols(n);
		for (int i = 0; i < l; i++) {
			cols[c[i]].first += 1;
		}
		for (int i = l; i < n; i++) {
			cols[c[i]].second += 1;
		}

		vector<int> lefts, rights;
		for (int i = 0; i < n; i++) {
			if (cols[i].first == 0 && cols[i].second == 0) {
				continue;
			}
			int mn = min(cols[i].first, cols[i].second);
			cols[i].first -= mn, cols[i].second -= mn;
			if (cols[i].first > 0) {
				lefts.push_back(cols[i].first);
			} else if (cols[i].second > 0) {
				rights.push_back(cols[i].second);
			}
		}

		if (accumulate(lefts.begin(), lefts.end(), 0) > accumulate(rights.begin(), rights.end(), 0)) {
			lefts.swap(rights);
		}

		int left_sum = accumulate(lefts.begin(), lefts.end(), 0), ans = 0;

		for (int i = 0; i < rights.size(); i++) {
			if (rights[i] % 2 != 0 && left_sum > 0) {
				left_sum -= 1;
				rights[i] -= 1;
				ans += 1;
			}
		}

		if (left_sum > 0) {
			for (int i = 0; i < rights.size(); i++) {
				int mn = min(left_sum, rights[i]);
				left_sum -= mn, rights[i] -= mn;
				ans += mn;
			}
		}

		int odd = 0;
		for (int i = 0; i < rights.size(); i++) {
			ans += rights[i] / 2;
			odd += rights[i] % 2 != 0;
		}

		ans += odd;
		cout << ans << '\n';
	}
	return 0;
}