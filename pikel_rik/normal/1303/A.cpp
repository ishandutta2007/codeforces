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

		int c = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '1') continue;
			bool left = false, right = false;
			for (int j = 0; j < i; j++) {
				left |= s[j] == '1';
			}

			for (int j = i + 1; j < s.length(); j++) {
				right |= s[j] == '1';
			}
			c += left && right;
		}
		cout << c << '\n';
	}
	return 0;
}