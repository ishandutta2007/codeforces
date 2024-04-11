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

		int two = 0;
		for (int i = 0; i < n; i++) {
			while (a[i] % 2 == 0) {
				two += 1;
				a[i] /= 2;
			}
		}

		int mx = max_element(a.begin(), a.end()) - a.begin();

		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if (i == mx) {
				ans += (1ll << two) * a[i];
			} else {
				ans += a[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}