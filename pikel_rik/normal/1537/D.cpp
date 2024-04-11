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

		if (n & (n - 1)) {
			if (n % 2 == 0) {
				cout << "Alice\n";
			} else {
				cout << "Bob\n";
			}
		} else {
			int msb = 32 - __builtin_clz(n) - 1;
			if (msb == 0 || msb % 2 != 0) {
				cout << "Bob\n";
			} else {
				cout << "Alice\n";
			}
		}
	}
	return 0;
}