#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long s, n, k;
		cin >> s >> n >> k;

		if (k > s) {
			cout << "NO\n";
			continue;
		}

		if (k == s) {
			cout << "YES\n";
			continue;
		}

		if (s >= 2 * n) {
			cout << "NO\n";
			continue;
		}

		if (k > n) {
			cout << "NO\n";
			continue;
		}

		if (n % k == 0) {
			cout << "YES\n";
		} else if (2 * k * (n / k) + n - k * (n / k) > s) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}