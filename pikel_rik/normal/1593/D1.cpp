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

		int g = 0;
		for (int i = 1; i < n; i++) {
			g = __gcd(g, abs(a[i] - a[i - 1]));
		}

		if (g == 0) {
			cout << "-1\n";
		} else {
			cout << g << '\n';
		}
	}
	return 0;
}