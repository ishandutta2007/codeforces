#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		map<int, int> mp;
		for (auto &x : a) mp[x]++;

		int ans = 0;
		for (auto &p : mp) ans = max(ans, p.second);
		cout << ans << '\n';
	}
	return 0;
}