#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n, n/=2;
		ll ans=0;
		for (int i=1; i<=n; ++i)
			ans+=8ll*i*i;
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