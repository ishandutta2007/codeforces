#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	string s; cin >> s;
	int cn = 0;
	if (n & 1) {
		cout << ":(";
	} else {
		int c = n / 2;
		int o = n / 2;
		for (int i = 0; i < n; ++i) {
			if (s[i] == ')') c--;
			else if(s[i] == '(') o--; 
		}
		for (int i = 0; i < n; ++i) {
			if (s[i] == '?') {
				if (o > 0) {
					s[i] = '(';
					o--;
				} else {
					s[i] = ')';
					c--;
				}
			}
		}
		int cn = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == ')') {
				cn--;
			} else {
				cn++;
			}
			if (i != n - 1) {
				if (cn <= 0) {
					cout << ":(";
					exit(0);
				} 
			} 
		}
		if (cn != 0) {
			cout << ":(";
		} else {
			cout << s;
		}
	}
}