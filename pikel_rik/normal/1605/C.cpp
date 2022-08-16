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

		bool adjacent = false;
		for (int i = 1; i < n; i++) {
			adjacent |= s[i] == s[i - 1] && s[i] == 'a';
		}

		if (adjacent) {
			cout << 2 << '\n';
			continue;
		}

		for (int i = 2; i < n; i++) {
			adjacent |= s[i] == s[i - 2] && s[i] == 'a';
		}

		if (adjacent) {
			cout << 3 << '\n';
			continue;
		}

		for (int i = 3; i < n; i++) {
			adjacent |= s[i] == s[i - 3] && s[i] == 'a' && s[i - 1] != s[i - 2];
		}

		if (adjacent) {
			cout << 4 << '\n';
			continue;
		}

		for (int i = 6; i < n; i++) {
			adjacent |= s[i] == s[i - 6] && s[i] == 'a' && s[i] == s[i - 3] && s[i - 1] != s[i - 4];
		}

		if (adjacent) {
			cout << 7 << '\n';
			continue;
		}

		cout << "-1\n";
	}
	return 0;
}