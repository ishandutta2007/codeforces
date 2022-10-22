#include <bits/stdc++.h>
using namespace std;

int a;
string s;

int main() {
	cin >> a >> s;
	if (s[3] > '5') {
		s[3] = '0';
	}
	if (a == 24) {
		// range from 0 to 23
		if ((s[0] - '0') * 10 + (s[1] - '0') > 23) s[0] = '0';
	}
	if (a == 12) {
		// range from 1 to 12
		int num = (s[0] - '0') * 10 + (s[1] - '0');
		if (num == 0) s[0] = '1';
		else if (num > 12) {
			if (s[1] != '0') s[0] = '0';
			else s[0] = '1';
		}
	}
	cout << s << endl;
}