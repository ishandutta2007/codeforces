#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> n(3);
	vector<ll> s(3);
	vector<int> mn(3);
	vector<vector<int>> bag(3);
	ll sum = 0;

	for (int& i : n) cin >> i;
	for (int i = 0; i < 3; ++i) {
		bag[i].resize(n[i]);
		for (int j = 0; j < n[i]; ++j) {
			cin >> bag[i][j];
			sum += bag[i][j];
		}
		s[i] = accumulate(bag[i].begin(), bag[i].end(), 0ll);
		mn[i] = *min_element(bag[i].begin(), bag[i].end());
	}
	ll ans = INT64_MIN;
	for (int i = 0; i < 3; ++i) {
		int a = i == 0 ? 1 : 0;
		int b = i == 1 ? a + 2 : a + 1;
		ll cur = sum - 2ll * (mn[a] + mn[b]);
		cur = max(cur, sum - 2 * s[a]);
		cur = max(cur, sum - 2 * s[b]);
		ans = max(ans, cur);
	}
	cout << ans;
	return 0;
}