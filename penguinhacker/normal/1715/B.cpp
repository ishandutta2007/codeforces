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
		int n, k, b;
		ll s;
		cin >> n >> k >> b >> s;
		ll extra=s-(ll)k*b;
		if (extra<0||extra>(ll)n*(k-1)) {
			cout << "-1\n";
			continue;
		}
		vector<ll> ans(n);
		ans[0]=(ll)k*b;
		for (int i=0; i<n; ++i) {
			int sub=min(extra, k-1ll);
			ans[i]+=sub;
			extra-=sub;
		}
		assert(extra==0);
		for (ll i : ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}