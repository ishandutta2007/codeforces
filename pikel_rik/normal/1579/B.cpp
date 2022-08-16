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

		vector<tuple<int, int, int>> operations;
		for (int i = 0; i < n; i++) {
			int mn = i;
			for (int j = i; j < n; j++) {
				if (a[j] < a[mn]) {
					mn = j;
				}
			}
			if (mn != i) {
				operations.emplace_back(i, n - 1, mn - i);
				rotate(a.begin() + i, a.begin() + mn, a.end());
			}
		}

		cout << operations.size() << '\n';
		for (auto &[l, r, d] : operations) {
			cout << l + 1 << ' ' << r + 1 << ' ' << d << '\n';
		}
	}
	return 0;
}