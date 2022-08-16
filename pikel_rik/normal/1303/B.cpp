#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long n, g, b;
		cin >> n >> g >> b;

		long long m = (n + 1) / 2;
		if (m % g == 0) {
			cout << max(n, (m / g - 1) * (g + b) + g) << '\n';
		} else {
			cout << max(n, (m / g) * (g + b) + (m % g)) << '\n';
		}
	}
	return 0;
}