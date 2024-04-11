#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int cnt(int i) {
	return __builtin_ctz(i);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		int all=0;
		for (ll& i : a) {
			cin >> i;
			all+=cnt(i);
		}
		ll ans=0;
		for (int i=0; i<n; ++i) {
			ll cur=a[i]<<(all-cnt(a[i]));
			for (int j=0; j<n; ++j)
				if (i^j)
					cur+=a[j]>>cnt(a[j]);
			ans=max(ans, cur);
		}
		cout << ans << "\n";
	}
	return 0;
}