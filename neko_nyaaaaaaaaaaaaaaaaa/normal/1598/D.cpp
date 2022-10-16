#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pair<int, int>> p;
		map<int, int> a, b;
		for (int i = 0; i < n; i++) {
			int x, y; cin >> x >> y; x--, y--;
			p.emplace_back(x, y);
			a[x]++; b[y]++;
		}

		int ans = n*(n-1)*(n-2)/6;
		for (auto [x, y]: p) {
			ans -= (a[x]-1)*(b[y]-1);
		}
		cout << ans << '\n'; 
	}

	return 0;
}