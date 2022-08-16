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

		sort(a.begin(), a.end());
		if (a[0] < 0) {
			cout << "NO\n";
		} else {
			cout << "YES\n" << 101 << '\n';
			for (int i = 0; i <= 100; i++) {
				cout << i << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}