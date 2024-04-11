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

		int ans = 0;
		for (int i = 1; i < n; i++) {
			int mx = max(a[i], a[i - 1]);
			int mn = min(a[i], a[i - 1]);

			int num = (mx + 1) / 2;
			while (num > mn) {
				ans += 1;
				num = (num + 1) / 2;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}