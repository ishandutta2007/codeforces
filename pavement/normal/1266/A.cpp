#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	while (n--) {
		cin >> s;
		bool h0 = 0;
		int sum = 0;
		for (char c : s)
			h0 |= (c == '0'),
			sum += c - '0';
		if (sum % 3 != 0 || !h0) {
			cout << "cyan\n";
			continue;
		}
		bool yes = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < s.size(); j++) {
				if (i == j) continue;
				string tmp = s.substr(i, 1) + s.substr(j, 1);
				if (stoi(tmp) % 4 == 0) {
					yes = 1;
					break;
				}
			}
			if (yes) break;
		}
		if (yes) cout << "red\n";
		else cout << "cyan\n";
	}
}