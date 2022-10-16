#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	string s; cin >> s;
	string t;
	for (char c: s) {
		if (c != 'a') t.push_back(c);
	}

	if (t.size() % 2) {cout << ":("; return 0;}
	if (t.substr(0, t.size()/2) != t.substr(t.size()/2, t.size()/2)) {cout << ":("; return 0;}

	for (int i = 0; i < t.size()/2; i++) {
		if (s.back() == 'a') {cout << ":("; return 0;}
		s.pop_back();
	}

	cout << s << '\n';
	
	return 0;
}