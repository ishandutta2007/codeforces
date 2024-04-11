#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	string s; cin >> s;
	int n = s.size();
	int j = -1;
	int k = 0;
	int ll = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '.') {
			j = i;
			ll = n - i;
		} 
	}
	if (j != -1) {
		s = s.substr(0, j) + s.substr(j + 1, n - j - 1);
	} 
	n = s.size();
	int y = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			y++;
		} else {
			break;
		}
	}
	if (y > 0) {
		s = s.substr(y, n - y);
	} 
	n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[n - i - 1] == '0') k++;
		else break;
	}
	s = s.substr(0, n - k);
	if (ll != -1) {
		k -= (ll - 1);
	} 
	if (s.size() == 1) {
		cout << s;
		if (k) 
			cout << "E" << k;
	} else {
		cout << s[0] << ".";
		for (int i = 1; i < s.size(); ++i) {
			cout << s[i];
		}
		if (k + s.size() - 1) 
			cout << "E" << k + (int)s.size() - 1;
	}
}