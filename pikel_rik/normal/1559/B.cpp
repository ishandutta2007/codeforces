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

		if (count(s.begin(), s.end(), '?') == n) {
			s[0] = 'B';
		}

		for (int i = 0; i < n; i++) {
			if (s[i] != '?') {
				for (int j = i - 1; j >= 0 && s[j] == '?'; j--) {
					if (s[j + 1] == 'B') {
						s[j] = 'R';
					} else {
						s[j] = 'B';
					}
				}
				for (int j = i + 1; j < n && s[j] == '?'; j++) {
					if (s[j - 1] == 'B') {
						s[j] = 'R';
					} else {
						s[j] = 'B';
					}
				}
			}
		}

		cout << s << '\n';
	}
	return 0;
}