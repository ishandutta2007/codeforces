/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

bool once(string const &s, string const &p) {
	int count = 0;
	int n = (int) s.length();
	int m = (int) p.length();
	for (int i = 0; i + m <= n; i++) {
		bool ok = true;
		for (int j = 0; j < m; j++) {
			if (s[i + j] != p[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			count++;
			if (count > 1) return false;
		}
	}
	return count == 1;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	string p = "abacaba";
	int m = (int) p.length();
	while (t--) {
		int len;
		string s;
		cin >> len >> s;
		bool found = false;
		for (int i = 0; i + m <= len; i++) {
			bool bad = false;
			for (int j = 0; j < m; j++) {
				if (s[i + j] != p[j] && s[i + j] != '?') {
					bad = true;
					break;
				}
			}
			if (!bad) {
				string g = s;
				for (int j = 0; j < m; j++) {
					g[i + j] = p[j];
				}
				for (int i = 0; i < len; i++) {
					if (g[i] == '?') {
						g[i] = 'z';
					}
				}
				if (once(g, p)) {
					cout << "Yes\n" << g << "\n";
					found = true;
					break;
				}
			}
		}
		if (!found) {
			cout << "No\n";
		}
	}	
}