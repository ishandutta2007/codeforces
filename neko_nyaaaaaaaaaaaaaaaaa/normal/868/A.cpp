#include <bits/stdc++.h>
using namespace std;

int main() {
	string pass;
	cin >> pass;
	int n;
	cin >> n;
	string s;
	bool p0 = false;
	bool p1 = false;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s[1] == pass[0]) {p0 = true;}
		if (s[0] == pass[1]) {p1 = true;}
		if (s == pass) {
			p0 = true;
			p1 = true;
			break;
		}
	}
	if (p0 && p1) {cout <<"YES";}
	else cout << "NO";
	return 0;
}