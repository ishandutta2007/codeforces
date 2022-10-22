#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll s, x, d;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> x, d=s-x;
	if (d&1||d<0) {cout << 0; return 0;}
	d>>=1;
	for (int i=0; i<=40; ++i) {
		if (((d>>i)&1)&&((x>>i)&1)) {cout << 0; return 0;}
	}
	int k=__builtin_popcountll(x);
	ll ans=(1ll<<k);
	if (s==x)
		ans-=2;
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/