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

		string s;
		cin >> s;

		int c = count(s.begin(), s.end(), 'M');
		if (n != 3 * c) {
			cout << "NO\n";
			continue;
		}

		for (int i = 0, j = c; i < n && j > 0; i++) {
			while (s[i] != 'T') {
				i += 1;
			}
			s[i] = '(', j -= 1;
		}

		bool ok = true;
		int opening = 0, half = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				opening += 1;
			} else if (s[i] == 'M') {
				opening -= 1;
				half += 1;
			} else {
				half -= 1;
			}
			ok &= opening >= 0 && half >= 0;
		}

		ok &= opening == 0 && half == 0;
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}