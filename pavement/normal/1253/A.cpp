#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100005], b[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		set<int> u;
		int ov = 0;
		bool inv = 0;
		for (int i = 1; i <= n; i++) {
			if ((a[i] != b[i] && ov) || a[i] > b[i]) inv = 1;
			else if (a[i] != b[i]) u.insert(b[i] - a[i]);
			if (a[i] != b[i] && a[i + 1] == b[i + 1]) ov++;
		}
		inv |= u.size() > 1;
		if (inv) cout << "NO\n";
		else cout << "YES\n";
	}
}