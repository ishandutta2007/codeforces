#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a > b) {
			swap(a, b);
		}

		int n = 2 * (b - a);

		if (a > n || b > n || c > n) {
			cout << "-1\n";
		} else {
			cout << (c + n / 2 <= n ? c + n / 2 : (c + n / 2) % n) << '\n';
		}
	}
	return 0;
}