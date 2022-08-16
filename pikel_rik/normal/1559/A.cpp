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

		int ans = a[0];
		for (int i = 1; i < n; i++) {
			ans &= a[i];
		}
		cout << ans << '\n';
	}
	return 0;
}