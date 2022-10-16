#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		bool ok = 1;
		for (char c: {'r', 'g', 'b'}) {
			char d = c; d -= 'a'; d += 'A';
			int C = 0, D = 0;
			for (int i = 0; i < 6; i++) {
				if (s[i] == c) C = i;
				if (s[i] == d) D = i;
			}
			if (C > D) ok = 0; 
		}
		if (ok) cout << "YES\n"; else cout << "NO\n";
	}

	return 0;
}