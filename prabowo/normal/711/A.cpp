#include <bits/stdc++.h>
using namespace std;

string s[1005];
int n;

int main () {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	
	int x = -1, y = -1;
	
	for (int i = 0; i < n; i++) {
		if (s[i][0] == s[i][1] && s[i][0] == 'O') x = i, y = 0;
		if (s[i][3] == s[i][4] && s[i][3] == 'O') x = i, y = 2;
	}
	
	if (x == -1) cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			if (i == x) {
				if (y == 0) cout << "++" << s[i].substr (2, 3) << "\n";
				else cout << s[i].substr (0, 3) << "++" << "\n";
			} else cout << s[i] << "\n";
		}
	}
	return 0;
}