#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 1, len = s.length(); i < len; i++) {
		if (islower(s[i])) {
			cout << s;
			return 0;
		}
	}
	if (islower(s[0])) cout << char(toupper(s[0]));
	else cout << char(tolower(s[0]));
	for (int i = 1, len = s.length(); i < len; i++) {
		cout << char(tolower(s[i]));
	}
}