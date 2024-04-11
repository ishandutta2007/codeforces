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

		int c1 = count(a.begin(), a.end(), 1), c2 = n - c1;

		bool ok = false;
		for (int i = 0; i <= c1; i++) {
			for (int j = 0; j <= c2; j++) {
				if (i + 2 * j == (c1 - i) + 2 * (c2 - j)) {
					ok = true;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}