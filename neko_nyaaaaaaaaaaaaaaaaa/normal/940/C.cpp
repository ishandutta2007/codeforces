#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> a(26, 0);
	for (int i = 0; i < s.size(); i++) {
		a[s[i] - 'a'] = 1;
	}
	if (k > n) {
		cout << s;
		k -= n;
		char c;
		for (char i = 0; i < 26; i++) {
			if (a[i]) {c = (i + 'a'); break;}
		}
		while (k--) {
			cout << c;
		}
		return 0;
	}
	char last;
	for (int i = 25; i >= 0; i--) {
		if (a[i]) {last = (i + 'a'); break;}
	}
	string ans;
	int pt;
	k--;
	for (int i = k; i >= 0; i--) {
		if (s[i] != last) {pt = i; break;}
	}
	for (int i = 0; i < 26; i++) {
		if (char(i + 'a') > s[pt] && a[i]) {s[pt] = (i + 'a'); break;}
	}
	char first;
	for (int i = 0; i < 26; i++) {
		if (a[i]) {first = (i + 'a'); break;}
	}
	for (int i = pt+1; i < s.size(); i++) {
		s[i] = first;
	}
	for (int i = 0; i <= k; i++) {
		cout << s[i];
	}
 	
	return 0;
}