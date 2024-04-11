#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int q, d;
		cin >> q >> d;

		auto is_lucky = [&](int x) -> bool {
			bool f = false;
			for (; x; x /= 10) {
				f |= x % 10 == d;
			}
			return f;
		};

		vector<bool> possible(100);
		possible[0] = true;

		for (int i = 1; i < 100; i++) {
			for (int j = 1; j <= i; j++) {
				possible[i] = possible[i] || (is_lucky(j) && possible[i - j]);
			}
		}

		while (q--) {
			int x;
			cin >> x;

			if (x >= 100) {
				cout << "YES\n";
			} else {
				cout << (possible[x] ? "YES" : "NO") << '\n';
			}
		}
	}
	return 0;
}