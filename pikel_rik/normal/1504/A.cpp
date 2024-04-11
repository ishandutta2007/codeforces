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

		int n = s.length();
		if (count(s.begin(), s.end(), 'a') == n) {
			cout << "NO\n";
		} else {
			for (int i = 0; i < n; i++) {
				if (s[i] != 'a') {
					s.insert(s.begin() + n - i, 'a');
					break;
				}
			}
			cout << "YES\n";
			cout << s << '\n';
		}
	}
	return 0;
}