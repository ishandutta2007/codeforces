#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<string> s(n), t(m);
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < m; i++) cin >> t[i];

	int q; cin >> q;
	while (q--) {
		int x; cin >> x; x--;
		int i = x % n, j = x % m;

		cout << s[i] << t[j] << '\n';
	}

	return 0;
}