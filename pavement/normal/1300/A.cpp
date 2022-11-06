#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		bool allnegone = 0;
		int s = 0, ts = 0;
		for (int a, i = 1; i <= n; i++) {
			cin >> a;
			allnegone |= (a != -1);
			if (a == 0) s++, a++;
			ts += a;
		}
		if (ts == 0 && !allnegone) cout << s + 2;
		else if (ts == 0) cout << s + 1;
		else cout << s;
		cout << '\n';
	}
}