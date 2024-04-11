#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (char &c : s) {
		if (c <= '4') continue;
		c = '9' - c + '0';
	}
	if (s[0] == '0') s[0] = '9';
	cout << s;
}