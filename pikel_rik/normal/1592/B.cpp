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
		for (auto &x : a) cin >> x;

		int l = n, r = -1;
		for (int i = 0; i < n; i++) {
			if (i < x && n - 1 - i < x) {
				l = min(l, i);
				r = max(r, i);
			}
		}

		auto b = a;
		sort(b.begin(), b.end());

		bool possible = true;
		for (int i = l; i <= r; i++) {
			possible &= a[i] == b[i];
		}

		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}