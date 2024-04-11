#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		map<int, int> cnt;
		for (auto &x : a) {
			cnt[x] += 1;
		}

		int ans = 0;
		for (auto [x, c] : cnt) {
			int now = c;
			if (x != cnt.rbegin()->first) {
				int previous = cnt.rbegin()->first + 1;
				for (int y = cnt.rbegin()->first; y > x; y = (x + y) / 2) {
					auto it = prev(cnt.upper_bound(y));
					if (it->first != previous && it->first != x) {
						now += 1;
					}
					previous = y = it->first;
				}
			}
			ans = max(ans, now);
		}
		cout << n - ans << '\n';
	}
	return 0;
}