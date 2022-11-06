#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int p = 0;
	cin >> s;
	char prev = s[0];
	for (int i = 1, l = s.length(); i < l; i++) {
		if (s[i] == prev) p++;
		else p = 0;
		if (p == 6) {
			cout << "YES";
			return 0;
		}
		prev = s[i];
	}
	cout << "NO";
}