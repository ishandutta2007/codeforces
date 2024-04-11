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

		vector<int> b(n);
		for (auto &x : b) cin >> x;

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		auto f = [&](int add) -> bool {
			int take = (n + add) - (n + add) / 4;
			int sum_a = add * 100;
			int remaining = take - add;
			for (int i = 1; i <= remaining; i++) {
				sum_a += a[n - i];
			}
			int sum_b = 0;
			for (int i = 1; i <= n && i <= take; i++) {
				sum_b += b[n - i];
			}
			return sum_a >= sum_b;
		};

		int lo = 0, hi = 3 * n;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (f(mid)) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		cout << lo << '\n';
	}
	return 0;
}