#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;

		string s;
		cin >> s;

		for (int iter = 0; iter < m; iter++) {
			string t = s;
			for (int i = 0; i < n; i++) {
				if (s[i] == '0') {
					int c = 0;
					c += i > 0 && s[i - 1] == '1';
					c += i + 1 < n && s[i + 1] == '1';
					if (c == 1) {
						t[i] = '1';
					}
				}
			}
			if (s == t) {
				break;
			}
			s.swap(t);
		}
		cout << s << '\n';
	}
	return 0;
}