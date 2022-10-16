#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	int lo = 1, hi = n;
	while (lo < hi) {
		int mid = (lo + hi + 1)/2;

		int l = 0, r = mid-1, ok = 0;
		for (auto [u, v]: a) {
			if (u >= r && v >= l) {
				l++, r--;
				if (r < 0) {
					ok = 1; break;
				}
			}
		}

		if (ok) {
			lo = mid;
		} else {
			hi = mid-1;
		}
	}
	cout << lo << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}