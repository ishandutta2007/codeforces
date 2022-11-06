#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[105];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		bool can = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] % 2 == 0) {
				cout << "1\n" << i << '\n';
				can = 1;
				break;
			}
		}
		if (!can) {
			if (n >= 2) cout << "2\n" << 1 << ' ' << 2 << '\n';
			else cout << "-1\n";
		}
 	}
}