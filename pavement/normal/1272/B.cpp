#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q, uc, dc, lc, rc;
	string s;
	cin >> q;
	while (q--) {
		cin >> s;
		uc = dc = lc = rc = 0;
		for (char c : s)
			if (c == 'U') uc++;
			else if (c == 'D') dc++;
			else if (c == 'L') lc++;
			else rc++;
		if (!uc || !dc) {
			cout << min(2ll, min(lc, rc) * 2) << '\n';
			for (int i = 0; i < min({1ll, lc, rc}); i++) cout << 'L';
			for (int i = 0; i < min({1ll, lc, rc}); i++) cout << 'R';
			cout << '\n';
		} else if (!lc || !rc) {
			cout << min(2ll, min(uc, dc) * 2) << '\n';
			for (int i = 0; i < min({1ll, uc, dc}); i++) cout << 'U';
			for (int i = 0; i < min({1ll, uc, dc}); i++) cout << 'D';
			cout << '\n';
		} else {
			uc = dc = min(uc, dc);
			lc = rc = min(lc, rc);
			cout << uc + lc + dc + rc << '\n';
			while (dc--) cout << 'D';
			while (lc--) cout << 'L';
			while (uc--) cout << 'U';
			while (rc--) cout << 'R';
			cout << '\n';
		}
	}
}