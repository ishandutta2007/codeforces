#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, k; cin >> n >> k;
	vector<int> a(n+1);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i] -= i;
	}
	vector<bool> b(n+1);
	for (int i = 0; i < k; i++) {
		int x; cin >> x; x--; b[x] = 1;
	}
	a[n] = 1000000001, b[n] = 1;

	int res = 0, prv = -1000000000, cnt = 0;
	vector<int> ans;
	for (int i = 0; i <= n; i++) {
		if (b[i]) {
			if (a[i] < prv) {
				cout << "-1\n"; exit(0);
			}
			while (ans.size() && ans.back() > a[i]) ans.pop_back();
			res += cnt - ans.size();
			ans.clear();
			prv = a[i]; cnt = 0;
		} else {
			cnt++;
			if (a[i] < prv) continue;

			auto it = upper_bound(ans.begin(), ans.end(), a[i]);
			if (it == ans.end()) ans.push_back(a[i]);
			else *it = a[i];
		}
	}
	cout << res << '\n';

	return 0;
}