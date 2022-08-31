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

		auto is_hill = [&](int i) -> bool {
			if (i <= 0 || i >= n - 1) return false;
			return a[i] > a[i - 1] && a[i] > a[i + 1];
		};

		auto is_valley = [&](int i) -> bool {
			if (i <= 0 || i >= n - 1) return false;
			return a[i] < a[i - 1] && a[i] < a[i + 1];
		};

		int c = 0;
		for (int i = 1; i < n - 1; i++) {
			c += is_hill(i) || is_valley(i);
		}

		int best = c;
		for (int i = 0; i < n; i++) {
			int actual = a[i];

			if (i + 1 < n) {
				int temp = c;
				for (int j = i - 1; j <= i + 1; j++) {
					temp -= is_hill(j) || is_valley(j);
				}
				a[i] = a[i + 1];
				for (int j = i - 1; j <= i + 1; j++) {
					temp += is_hill(j) || is_valley(j);
				}
				best = min(best, temp);
			}
			if (i - 1 >= 0) {
				int temp = c;
				a[i] = actual;
				for (int j = i - 1; j <= i + 1; j++) {
					temp -= is_hill(j) || is_valley(j);
				}
				a[i] = a[i - 1];
				for (int j = i - 1; j <= i + 1; j++) {
					temp += is_hill(j) || is_valley(j);
				}
				best = min(best, temp);
			}
			a[i] = actual;
		}

		cout << best << '\n';
	}
	return 0;
}