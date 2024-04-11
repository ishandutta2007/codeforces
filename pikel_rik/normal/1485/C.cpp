#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int b, x, y;
		cin >> x >> y;

		long long ans = 0;
		for (b = 2; b <= y && b * b <= x; b++) {
			if (x / (b + 1) >= b - 1) {
				ans += b - 1;
			}
		}

		while (b <= y) {
			int lo = b, hi = y;
			while (lo < hi) {
				int mid = (lo + hi + 1) / 2;
				if (x / (mid + 1) == x / (b + 1)) {
					lo = mid;
				} else hi = mid - 1;
			}
			ans += (long long)(lo - b + 1) * (x / (b + 1));
			b = lo + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}