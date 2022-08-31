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

		if (is_sorted(a.begin(), a.end())) {
			cout << 0 << '\n';
		} else if (a[0] == 1 || a[n - 1] == n) {
			cout << 1 << '\n';
		} else if (a[0] == n && a[n - 1] == 1) {
			cout << 3 << '\n';
		} else {
			cout << 2 << '\n'; 
		}
	}
	return 0;
}