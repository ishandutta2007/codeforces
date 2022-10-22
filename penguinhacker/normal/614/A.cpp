#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll l, r, k;
	cin >> l >> r >> k;
	ll c=1;
	vector<ll> ans;
	while(c<=r) {
		if (c>=l)
			ans.push_back(c);
		if ((long double)c*k>2e18)
			break;
		c*=k;
	}
	if (ans.empty()) {
		cout << -1;
		return 0;
	}
	for (ll i : ans)
		cout << i << " ";
	return 0;
}