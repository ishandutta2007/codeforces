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

		sort(a.begin(), a.end(), [&](int x, int y) {
			return (x % 2) < (y % 2);
		});

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += __gcd(a[i], 2 * a[j]) > 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}