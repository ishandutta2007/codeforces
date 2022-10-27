#include <bits/stdc++.h>
using namespace std;

string prune(string s) {
	reverse(s.begin(), s.end());
	while (s.size() && s.back() == '0') {
		s.pop_back();
	}
	if (s == "") s = "0";
	else reverse(s.begin(), s.end());
	return s;
}

string OR(string s, string t) {
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());

	string ans;
	for (int i = 0; i < max(s.size(), t.size()); i++) {
		char cz = '0';
		if (i < s.size() && s[i] == '1') cz = '1';
		if (i < t.size() && t[i] == '1') cz = '1';
		ans.push_back(cz);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	string s; cin >> s;

	string ans = prune(s);
	for (int i = 1; i <= min(n-1, 50); i++) {
		string t = s;
		for (int j = 0; j < i; j++) {
			t.pop_back();
		}
		string tmp = prune(OR(t, s));
		if (tmp > ans) ans = tmp;
	}
	cout << ans << '\n';

	return 0;
}