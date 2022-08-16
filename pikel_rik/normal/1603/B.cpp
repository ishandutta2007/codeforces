#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int x, y;
		cin >> x >> y;

		if (y < x) {
			cout << x + y << '\n';
		} else if (y == x) {
			cout << x << '\n';
		} else {
			cout << y - (y % x) / 2 << '\n';
		}
	}
	return 0;
}