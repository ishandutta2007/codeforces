#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	string s, t;
	cin >> s >> t;
	
	bool asterisk = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') asterisk = 1;
	}
	
	if (!asterisk) {
		if (s == t) {cout << "YES";}
		else {cout << "NO";}
		return 0;
	}
	
	if (n-1 > m) {cout << "NO"; return 0;}
	
	while (s.back() != '*') {
		if (s.back() != t.back()) {cout << "NO"; return 0;}
		s.pop_back(); t.pop_back();
	}
	
	for (int i = 0; s[i] != '*'; i++) {
		if (s[i] != t[i]) {cout << "NO"; return 0;}
	}
	
	cout << "YES";
	
	return 0;
}