#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		pair<ll, int> mx={-1, -1};
		ll mn=1e18;
		for (int i=0; i<n; ++i) {
			vector<ll> a(m);
			ll cur=0;
			for (int j=0; j<m; ++j) {
				cin >> a[j];
				cur+=j*a[j];
			}
			mn=min(mn, cur);
			mx=max(mx, {cur, i+1});
		}
		cout << mx.second << " " << mx.first-mn << "\n";
	}
	return 0;
}