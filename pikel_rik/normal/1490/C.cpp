#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long x;
		cin >> x;

		bool ok = false;
		for (int i = 1; (long long)i * i * i < x; i++) {
			long long rem = x - (long long)i * i * i;
			int lo = 1, hi = 10000;
			while (lo < hi) {
				int mid = (lo + hi) / 2;
				if ((long long)mid * mid * mid >= rem)
					hi = mid;
				else lo = mid + 1;
			}
			ok |= rem == (long long)lo * lo * lo;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}