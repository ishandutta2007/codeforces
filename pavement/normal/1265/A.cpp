#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int l = s.size(), c = 0;
		for (int i = 0; i < l; i++) {
			if (s[i] == '?') c++;
			else if (c) {
				for (int j = i - c; j < i - 1; j++)
					if (j && s[j - 1] == 'c') s[j] = 'a';
					else if (j) s[j] = s[j - 1] + 1;
					else if (!j) s[j] = 'a';
				if (i > 1 && s[i - 2] != 'a' && s[i] != 'a') s[i - 1] = 'a';
				else if (i > 1 && s[i - 2] != 'b' && s[i] != 'b') s[i - 1] = 'b';
				else if (i > 1 && s[i - 2] != 'c' && s[i] != 'c') s[i - 1] = 'c';
				else if (i <= 1 && s[i] == 'c') s[i - 1] = 'a';
				else if (i <= 1) s[i - 1] = s[i] + 1;
				c = 0;
			}
		}
		if (c) {
			for (int j = l - c; j < l; j++)
				if (j && s[j - 1] == 'c') s[j] = 'a';
				else if (j) s[j] = s[j - 1] + 1;
				else if (!j) s[j] = 'a';
		}
		bool flag = 0;
		for (int i = 0; i < l - 1; i++)
			flag = max(flag, s[i] == s[i + 1]);
		if (!flag) cout << s << '\n';
		else cout << "-1\n";
	}
}