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

		int n = (int) s.length();

		int l = find(s.begin(), s.end(), 'a') - s.begin(), r = l;
		for (int i = 1; l != n && i < n; i++) {
			if (l > 0 && s[l - 1] == 'a' + i) {
				l -= 1;
			} else if (r + 1 < n && s[r + 1] == 'a' + i) {
				r += 1;
			} else {
				l = n;
			}
		}
		cout << (l != n ? "YES" : "NO") << '\n';
	}
	return 0;
}