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

		long long ans = a[0] + a[n - 1];
		for (int i = 0; i < n; i++) {
			if (i > 0 && a[i - 1] < a[i]) {
				ans += a[i] - a[i - 1];
			}
			if (i + 1 < n && a[i + 1] < a[i]) {
				ans += a[i] - a[i + 1];
			}
		}

		for (int i = 0; i < n; i++) {
			int left = (i == 0 ? 0 : a[i - 1]);
			int right = (i + 1 == n ? 0 : a[i + 1]);
			if (left < a[i] && right < a[i]) {
				ans -= a[i] - max(left, right);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}