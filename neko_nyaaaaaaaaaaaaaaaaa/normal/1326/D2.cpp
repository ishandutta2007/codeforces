#include <bits/stdc++.h>
using namespace std;

//code taken from https://cp-algorithms.com/string/prefix-function.html
vector<int> prefix_function(string s) {
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

string solvey(string s) {
	string t1 = s + "*";
	reverse(s.begin(), s.end());
	t1 += s;
	reverse(s.begin(), s.end());

	vector<int> pi1 = prefix_function(t1);
	int len1 = pi1.back();

	reverse(s.begin(), s.end());
	string t2 = s + "*";
	reverse(s.begin(), s.end());
	t2 += s;
	vector<int> pi2 = prefix_function(t2);
	int len2 = pi2.back();

	string res;
	if (len1 >= len2) {
		for (int i = 0; i < len1; i++) {
			res.push_back(s[i]);
		}
	} else {
		for (int i = s.size()-1, j = 0; j < len2; i--, j++) {
			res.push_back(s[i]);
		}
	}
	return res;
}

void solve() {
	int n; string s;
	cin >> s; n = s.size();
	
	int longest_bord = 0;
	int l = 0, r = n-1;
	while (l <= r && s[l] == s[r]) {
		longest_bord += 1 + (l != r);
		l++; r--;
	}

	if (longest_bord == n) {
		cout << s << '\n';
		return;
	}

	string ns;
	for (int i = l; i <= r; i++) {
		ns.push_back(s[i]);
	}

	string ans = solvey(ns);
	for (int i = 0; i < l; i++) {
		cout << s[i];
	}
	cout << ans;
	for (int i = l-1; i >= 0; i--) {
		cout << s[i];
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	int t; cin >> t;
	while (t--) {
		solve();
	}
 
	return 0;
}