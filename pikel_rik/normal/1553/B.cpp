#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	while (q--) {
		string s, t;
		cin >> s >> t;

		int n = (int) s.length();
		int m = (int) t.length();

		bool possible = false;
		for (int i = 0; i < n; i++) {
			for (int j = i, k = 0; j < n; j++, k++) {
				if (k + 1 == m && s[j] == t[k]) {
					possible = true;
					break;
				}
				if (k + 1 == m || s[j] != t[k]) {
					break;
				}

				if (j - (m - k - 1) < 0) {
					continue;
				}

				bool ok = true;
				for (int ii = 1; ii <= m - k - 1; ii++) {
					ok &= s[j - ii] == t[k + ii];
				}
				possible |= ok;
			}
		}
		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}