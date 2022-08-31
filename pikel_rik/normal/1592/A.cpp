#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, H;
		cin >> n >> H;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		sort(a.rbegin(), a.rend());

		int ans = 2 * (H / (a[0] + a[1]));
		H %= a[0] + a[1];

		if (H > 0) {
			if (H <= a[0]) {
				ans += 1;
			} else {
				ans += 2;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}