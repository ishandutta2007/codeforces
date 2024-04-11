#include <bits/stdc++.h>
using namespace std;
 
bool check(string s, int n, int k) {
	for (int i = 0; i < k; i++) {
		char c = 0;
		for (int j = 0; j < n; j += k) {
			if (c == 0) {
				c = s[j];
			} else if (c != s[j]) {
				return 0;
			}
		}
	}
	return 1;
}
 
void add_one(string &s) {
	for (int i = s.size()-1; i >= 0; i--) {
		if (s[i] == '9') {
			s[i] = '0';
		} else {
			s[i]++; return;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	int n, k; cin >> n >> k;
	string s; cin >> s;
 
 
	// try this one first
	string zc; int petr = 0;
	while (zc.size() < n) {
		zc.push_back(s[petr]);
		petr = (petr + 1) % k;
	}
 
	if (zc >= s) {
		cout << n << '\n' << zc << '\n';
		exit(0);
	}
 
	// extract the first k digits
	string fk;
	for (int i = 0; i < k; i++) {
		fk.push_back(s[i]);
	}
	add_one(fk);
 
	zc.clear(); petr = 0;
	while (zc.size() < n) {
		zc.push_back(fk[petr]);
		petr = (petr + 1) % k;
	}
 
	cout << n << '\n' << zc << '\n';
 
	return 0;
}