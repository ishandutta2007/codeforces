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

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		sort(a.begin(), a.end());

		long long ans = 0;
		for (auto &x : a) {
			//l <= x + y <= r
			//l - x <= y <= r - x
			auto lb = lower_bound(a.begin(), a.end(), l - x);
			auto ub = upper_bound(a.begin(), a.end(), r - x);
			ans += ub - lb;
			ans -= l <= 2 * x && 2 * x <= r;
		}
		ans /= 2;
		cout << ans << '\n';
	}
	return 0;
}