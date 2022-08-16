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

		if (n % 2 == 0) {
			cout << 0 << '\n';
		} else {
			vector<int> digits;
			for (; n > 0; n /= 10) {
				digits.push_back(n);
			}
			if (digits.back() % 2 == 0) {
				cout << 1 << '\n';
			} else if (any_of(digits.begin(), digits.end(), [](int x) { return x % 2 == 0; })) {
				cout << 2 << '\n';
			} else {
				cout << -1 << '\n';
			}
		}
	}
	return 0;
}