#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, u, v;
		cin >> n >> u >> v;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		bool same = true;
		for (int i = 0; i < n; i++) same &= a[i] == a[0];

		if (same) {
			cout << v + min(u, v) << '\n';
			continue;
		}

		bool f = true;
		for (int i = 1; i < n; i++) {
			f &= abs(a[i] - a[i - 1]) <= 1;
		}

		if (f) {
			cout << min(u, v) << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
	return 0;
}