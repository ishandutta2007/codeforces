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

		int neg = 0, ans = 0;
		for (auto &x : a) {
			ans += x <= 0;
			neg += x < 0;
		}

		sort(a.begin(), a.end());
		int pos = upper_bound(a.begin(), a.end(), 0) - a.begin();

		if (pos != n) {
			bool possible = true;
			for (int i = 1; i < n && a[i] <= 0; i++) {
				possible &= a[i] - a[i - 1] >= a[pos];
			}
			if (possible) {
				ans += 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}