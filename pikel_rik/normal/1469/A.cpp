#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int n = int(s.length());

		if (n % 2 != 0) {
			cout << "NO\n";
			continue;
		}

		int c0 = n / 2, c1 = n / 2;
		for (char ch : s) {
			c0 -= ch == '(';
			c1 -= ch == ')';
		}

		if (c0 < 0 || c1 < 0) {
			cout << "NO\n";
			continue;
		}

		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '?') {
				if (c1) {
					s[i] = ')';
					c1 -= 1;
				} else {
					s[i] = '(';
					c0 -= 1;
				}
			}
		}

		bool ok = true;
		for (int i = 0, c = 0; i < n; i++) {
			if (s[i] == '(') {
				c += 1;
			} else {
				c -= 1;
			}
			ok &= c >= 0;
		}

		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}