#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, a[200000];

void solve() {
	map<int, int> mp;
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		if (a[i]%k!=0)
			mp[a[i]%k]++;
	}
	ll ans=0;
	for (auto x : mp)
		ans=max(ans, 1ll*k*x.second-x.first);
	cout << (ans==0?0:ans+1) << '\n';
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

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/