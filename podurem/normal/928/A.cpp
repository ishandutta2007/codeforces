#include <bits/stdc++.h>
 
using namespace std;

int good(char c, char t) {
	if (c == 'o' && t == '0' || t == 'o' && c == '0') return 1;
	if (c == t) return 1;
	if ((c == '1' || c == 'l' || c == 'i') && (t == '1' || t == 'l' || t == 'i')) return 1;
	return 0;
}

int main() {
	string s;
	cin >> s;
	for (auto &c : s) c = tolower(c);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string t;
		cin >> t;
		for (auto &c : t) c = tolower(c);
		int ok = 0;
		if ((int)s.size() == (int)t.size()) {
			for (int j = 0; j < (int)s.size(); ++j)
				ok += good(s[j], t[j]);
			if (ok == (int)s.size())
				return 0 * puts("No");
		}
	}
	puts("Yes");
    return 0;
}