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

		int ab = a + b, cc = 2 * c;
		int diff = cc - ab;

		if (diff % 3 == 0) {
			cout << 0 << '\n';
		} else {
			cout << 1 << '\n';
		}
	}
	return 0;
}