#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = 10 * (n % 10 - 1);

		while (n > 0) {
			int i = n;
			while (i > 0) {
				ans++; i /= 10;
			}
			n /= 10;
		}
		cout << ans << '\n';
	}

	return 0;
}