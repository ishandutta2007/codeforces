#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	string a, b, c;
	cin >> t;
	while (t--) {
		bool can = 1;
		cin >> a >> b >> c;
		for (int i = 0; i < a.size(); i++) {
			if (!(c[i] == b[i] || c[i] == a[i])) {
				can = 0;
			}
		}
		if (can) cout << "YES\n";
		else cout << "NO\n";
	}
}