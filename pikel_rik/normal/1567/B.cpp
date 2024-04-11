#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	auto xor_upto = [&](int x) -> int {
		if (x % 4 == 0) {
			return x;
		} else if (x % 4 == 1) {
			return 1;
		} else if (x % 4 == 2) {
			return x + 1;
		} else {
			return 0;
		}
	};

	while (t--) {
		int a, b;
		cin >> a >> b;

		if (xor_upto(a - 1) == b) {
			cout << a << '\n';
		} else if ((xor_upto(a - 1) ^ b) != a) {
			cout << a + 1 << '\n';
		} else {
			cout << a + 2 << '\n';
		}
	}
	return 0;
}