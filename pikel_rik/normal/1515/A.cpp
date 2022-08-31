#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, x;
		cin >> n >> x;

		vector<int> a(n);
		for (auto &y : a) cin >> y;

		if (accumulate(a.begin(), a.end(), 0) == x) {
			cout << "NO\n";
		} else {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum += a[i];
				if (sum == x) {
					if (i + 1 < n) {
						swap(a[i], a[i + 1]);
					} else {
						swap(a[i], a[i - 1]);
					}
				}
			}
			cout << "YES\n";
			for (auto &y : a) cout << y << ' ';
			cout << '\n';
		}
	}
	return 0;
}