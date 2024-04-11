#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, c;
		cin >> n >> c;

		vector<int> a(n), b(n - 1);
		for (auto &x : a) cin >> x;
		for (auto &x : b) cin >> x;
		b.push_back(0);

		long long cur = 0, days = 0, ans = LLONG_MAX;

		for (int i = 0; i < n; i++) {
			if (c > cur) {
				ans = min(ans, days + (c - cur + a[i] - 1) / a[i]);
			} else {
				ans = min(ans, days);
			}
			if (b[i] > cur) {
				long long temp = (b[i] - cur + a[i] - 1) / a[i];
				days += temp;
				cur += a[i] * temp;
			}
			cur -= b[i];
			days += 1;
		}

		cout << ans << '\n';
	}
	return 0;
}