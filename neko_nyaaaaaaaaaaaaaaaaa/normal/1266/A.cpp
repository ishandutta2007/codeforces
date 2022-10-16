#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		// contain 0
		// contain even digit
		// sum divisible by 3

		int has0 = 0, ev = 0, sum = 0;
		for (char c: s) {
			if (!has0 && c == '0') has0 = 1;
			else if (((c - '0') % 2) == 0) ev = 1;
			sum += (c - '0');
		}
		if (has0 && ev && ((sum % 3) == 0)) {
			cout << "red\n";
		} else {
			cout << "cyan\n";
		}
	}

	return 0;
}