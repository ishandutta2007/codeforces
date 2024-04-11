#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n);
	for (auto &it : a)
		cin >> it;
	sort(a.begin(), a.end());

	int ans = 0;

	for (int i = 0; i < n; i++){
		if (a[i] >= r) break;

		auto it1 = lower_bound(a.begin() + i + 1, a.end(), l - a[i]);
		auto it2 = upper_bound(a.begin() + i + 1, a.end(), r - a[i]);
		ans += (it2 - it1);
	}
	cout << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}