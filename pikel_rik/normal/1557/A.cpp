#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(12);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		sort(a.begin(), a.end());

		double ans = LLONG_MIN;

		long long left_sum = 0, right_sum = accumulate(a.begin(), a.end(), 0ll);
		for (int i = 0; i + 1 < n; i++) {
			left_sum += a[i], right_sum -= a[i];
			ans = max(ans, (double)left_sum / (i + 1) + (double)right_sum / (n - i - 1));
		}
		cout << ans << '\n';
	}
	return 0;
}