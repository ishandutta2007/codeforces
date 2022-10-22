#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	map<ll, int> mp;
	for (int i=0; i<n; ++i) {
		ll l, r;
		cin >> l >> r;
		++mp[l], --mp[r+1];
	}
	int cur=0;
	ll last=-1;
	vector<ll> ans(n+1);
	for (auto& x : mp) {
		if (cur)
			ans[cur]+=x.first-last;
		last=x.first;
		cur+=x.second;
	}
	for (int i=1; i<=n; ++i)
		cout << ans[i] << " ";
	return 0;
}