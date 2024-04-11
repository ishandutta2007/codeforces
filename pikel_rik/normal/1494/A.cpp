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

		array<int, 3> cnt = {0};
		for (char ch : s) {
			cnt[ch - 'A']++;
		}

		int half = -1;
		for (int i = 0; i < 3; i++) {
			if (2 * cnt[i] == int(s.length())) {
				half = i;
			}
		}

		if (half == -1) {
			cout << "NO\n";
			continue;
		}

		bool final = false;

		bool ok = true;
		int c = 0;
		for (char ch : s) {
			if (ch - 'A' == half)
				c += 1;
			else c -= 1;
			ok &= c >= 0;
		}

		final |= ok;

		ok = true, c = 0;
		for (char ch : s) {
			if (ch - 'A' == half)
				c -= 1;
			else c += 1;
			ok &= c >= 0;
		}

		final |= ok;
		cout << (final ? "YES" : "NO") << '\n';
	}
	return 0;
}