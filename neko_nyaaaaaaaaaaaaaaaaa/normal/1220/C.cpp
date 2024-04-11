#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s; cin >> s;
	vector<int> cnt(26);
	for (int i = 0; i < s.size(); i++) {
		int annwin = 0;
		for (int j = 0; j + 'a' < s[i]; j++) {
			if (cnt[j]) annwin = 1;
		}
		if (annwin) cout << "Ann\n";
		else cout << "Mike\n";

		cnt[s[i] - 'a']++;
	}

	return 0;
}