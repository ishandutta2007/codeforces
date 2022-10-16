#include <bits/stdc++.h>
using namespace std;

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	if (n == 1) {
		cout << "? 1 1\n";
		char c; cin >> c;
		cout << "! " << c << '\n';
		exit(0);
	}
	multiset<string> s[101];

	cout << "? 1 " << n << '\n';
	for (int i = 0; i < n*(n-1)/2 + n; i++) {
		string str; cin >> str;
		sort(str.begin(), str.end());
		s[str.size()].insert(str);
	}
	cout << "? 2 " << n << '\n';
	for (int i = 0; i < (n-1)*(n-2)/2 + (n-1); i++) {
		string str; cin >> str;
		sort(str.begin(), str.end());
		s[str.size()].erase(s[str.size()].find(str));
	}

	string ans;
	for (int i = 1; i <= n; i++) {
		string str = *s[i].begin();

		vector<int> cnt(26);
		for (char c: ans) cnt[c - 'a']++;
		for (char c: str) cnt[c - 'a']--;

		for (int j = 0; j < 26; j++) {
			if (cnt[j]) ans.push_back(j + 'a');
		}
	}
	cout << "! " << ans << '\n';

	return 0;
}