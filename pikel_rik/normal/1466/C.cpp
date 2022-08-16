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
		vector<bool> changed(n);

		for (int i = 1; i < n; i++) {
			if (!changed[i - 1] && s[i] == s[i - 1]) {
				changed[i] = true;
			} else if (i - 2 >= 0 && !changed[i - 2] && s[i] == s[i - 2]) {
				changed[i] = true;
			}
		}

		cout << count(changed.begin(), changed.end(), true) << '\n';
	}
	return 0;
}