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

		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}

		auto f = [&](int c) -> bool {
			int taken = 0;
			for (int i = 0; i < n; i++) {
				if (b[i] >= taken && a[i] >= c - taken - 1) {
					taken += 1;
				}
			}
			return taken >= c;
		};

		int lo = 1, hi = n;
		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if (f(mid)) {
				lo = mid;
			} else {
				hi = mid - 1;
			}
		}
		cout << lo << '\n';
	}
	return 0;
}