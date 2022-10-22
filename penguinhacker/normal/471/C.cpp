#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int ans=0;
ll n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; n-2*i>=0; ++i) {
		ll x=n-2*i;
		if (x%3!=0)
			continue;
		x/=3;
		if (1ll*(i-1)*i/2>x)
			break;
		++ans;
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/