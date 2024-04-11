#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<int> t(n), x(n);
		for (int i = 0; i < n; i++) cin >> t[i] >> x[i];

		int ans = 0, last_x = 0, last_w = x[0];

		for (int i = 1; i < n; i++) {
			if (t[i] - t[i - 1] >= abs(last_x - last_w)) {
				ans += min(last_x, last_w) <= x[i - 1] && x[i - 1] <= max(last_x, last_w);
				last_x = last_w;
				last_w = x[i];
			} else {
				if (last_x < last_w) {
					ans += last_x <= x[i - 1] && x[i - 1] <= last_x + t[i] - t[i - 1];
					last_x += t[i] - t[i - 1];
				} else {
					ans += last_x - (t[i] - t[i - 1]) <= x[i - 1] && x[i - 1] <= last_x;
					last_x -= t[i] - t[i - 1];
				}
			}
		}

		ans += min(last_x, last_w) <= x[n - 1] && x[n - 1] <= max(last_x, last_w);
		cout << ans << '\n';
	}
	return 0;
}