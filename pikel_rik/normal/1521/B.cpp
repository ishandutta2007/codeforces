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

		cout << n - 1 << '\n';
		for (int i = mn - 1, x = a[mn] + 1; i >= 0; i--, x++) {
			cout << i + 1 << ' ' << mn + 1 << ' ' << x << ' ' << a[mn] << '\n';
		}
		for (int i = mn + 1, x = a[mn] + 1; i < n; i++, x++) {
			cout << i + 1 << ' ' << mn + 1 << ' ' << x << ' ' << a[mn] << '\n';
		}
	}
	return 0;
}