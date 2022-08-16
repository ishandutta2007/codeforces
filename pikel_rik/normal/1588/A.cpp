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

		vector<int> a(n), b(n);
		for (auto &x : a) cin >> x;
		for (auto &x : b) cin >> x;

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		bool possible = true;
		for (int i = 0; i < n; i++) {
			possible &= a[i] == b[i] || a[i] == b[i] - 1;
		}

		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}