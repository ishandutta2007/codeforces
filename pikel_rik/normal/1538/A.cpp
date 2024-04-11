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

		int mn = min_element(a.begin(), a.end()) - a.begin();
		int mx = max_element(a.begin(), a.end()) - a.begin();

		int ans = max(mn, mx) + 1;
		ans = min(ans, max(n - mn - 1, n - mx - 1) + 1);
		ans = min(ans, min(mn, mx) + 1 + min(n - mn - 1, n - mx - 1) + 1);
		cout << ans << '\n';
	}
	return 0;
}