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
		int m, d, w; cin >> m >> d >> w;
		w/=__gcd(w, d-1);
		int k=min(d, m);
		int base=k/w;
		int res=k%w;
		ll ans=1ll*(res)*(base+1)*(base)+1ll*(w-res)*(base)*(base-1);
		ans/=2;
		cout << ans << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/