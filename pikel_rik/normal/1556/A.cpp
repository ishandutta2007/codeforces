#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int c, d;
		cin >> c >> d;

		if (c % 2 != d % 2) {
			cout << "-1\n";
		} else {
			if (c == d) {
				cout << (c > 0) << '\n';
			} else {
				cout << 2 << '\n';
			}
		}
	}
	return 0;
}