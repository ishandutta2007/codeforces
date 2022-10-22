#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i, i*=2;
	ll sum=accumulate(a.begin(), a.end(), 0ll);
	if (sum%n) {
		cout << "0\n";
		return;
	}
	map<int, int> mp;
	int avg=sum/n;
	for (int i : a)
		++mp[i-avg];
	ll ans=(ll)mp[0]*(mp[0]-1);
	for (int i : a)
		if (i^avg)
			ans+=mp[avg-i];
	cout << ans/2 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}