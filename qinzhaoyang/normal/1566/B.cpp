#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int T;
string s;

int main() {
	ios::sync_with_stdio(false);
	for (cin >> T; T; T--) {
		cin >> s; int c = 0;
		if (s[0] == '0') c++;
		for (int i = 1; i < s.size(); i++)
			if (s[i - 1] != '0' && s[i] == '0')
				c++;
		if (c < 2) cout << c << endl;
		else cout << 2 << endl;
	}
	return 0;
}