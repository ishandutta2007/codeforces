#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		m = min(m, n);

		string s; cin >> s;
		while (m--) {
			string t = s;
			for (int i = 0; i < n; i++) {
				if (t[i] == '1') continue;
				int cnt = 0;
				if (i > 0) cnt += (s[i-1] == '1');
				if (i+1 < n) cnt += (s[i+1] == '1');
				if (cnt == 1) t[i] = '1';
			}
			swap(t, s);
		}
		cout << s << '\n';
	}

	return 0;
}