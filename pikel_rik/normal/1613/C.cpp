#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n; long long h;
		cin >> n >> h;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		auto f = [&](long long k) -> bool {
			long long damage = 0;
			for (int i = 1; i < n; i++) {
				if (a[i] - a[i - 1] >= k) {
					damage += k;
				} else {
					damage += a[i] - a[i - 1];
				}
			}
			damage += k;
			return damage >= h;
		};

		long long lo = 1, hi = h;
		while (lo < hi) {
			long long mid = lo + (hi - lo) / 2;
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