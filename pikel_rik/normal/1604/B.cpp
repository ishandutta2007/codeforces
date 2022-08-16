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

		bool inversion = false;
		for (int i = 1; i < n; i++) {
			inversion |= a[i - 1] >= a[i];
		}

		if (n % 2 == 0 || inversion) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}