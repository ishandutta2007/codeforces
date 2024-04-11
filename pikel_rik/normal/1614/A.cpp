#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, l, r, k;
		cin >> n >> l >> r >> k;

		vector<int> a(n);
		for (auto &x : a) {
			cin >> x;
			if (x < l || r < x) {
				x = r + 1;
			}
		}

		sort(a.begin(), a.end());

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] <= r && a[i] <= k) {
				ans += 1;
				k -= a[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}