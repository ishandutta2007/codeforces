#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isPal(string &s) {
	//cout << "PAL "<< s << '\n';
	for (int i = 0; i < s.size() / 2; i++)
		if (s[i] != s[s.size() - i - 1]) return 0;
	return 1;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int l = 0, r = s.size() - 1, m = 0, ansl = -1e9, ansr = -1e9;
		bool ansly = 0, ansry = 0;
		for (; l <= r; )
			if (s[l] == s[r]) l++, r--;
			else break;
		string t = "";
		for (int i = l; i <= r; i++) {
			t.push_back(s[i]);
			if (isPal(t) && i - l >= m) {
				ansl = i;
				ansly = 1;
				m = max(m, i - l);
			}
		}
		t = "";
		for (int i = r; i >= l; i--) {
			t.push_back(s[i]);
			if (isPal(t) && r - i >= m) {
				ansl = ansly = 0;
				ansr = i;
				ansry = 1;
				m = max(m, r - i);
			}
		}
		if (!ansly && !ansry) {
			if (l > r) {
				cout << s;
				cout << '\n';
			} else {
				for (int i = 0; i < l; i++) cout << s[i];
				for (int i = r + 1; i < s.size(); i++) cout << s[i];
				cout << '\n';
			}
		} else if (ansly) {
			//cout << " L "<< ansl << '\n';
			for (int i = 0; i <= ansl; i++) cout << s[i];
			for (int i = r + 1; i < s.size(); i++) cout << s[i];
			cout << '\n';
		} else {
			//cout << " R " << ansr << '\n';
			for (int i = 0; i < l; i++) cout << s[i];
			for (int i = ansr; i < s.size(); i++) cout << s[i];
			cout << '\n';
		}
	}
}