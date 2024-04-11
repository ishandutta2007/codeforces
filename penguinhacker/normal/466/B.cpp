#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, a, b;
	cin >> n >> a >> b, n*=6;
	if (a*b>=n) {
		cout << a*b << '\n' << a << ' ' << b;
		return 0;
	}
	array<ll, 2> ans={(int)1e9, (int)1e9};
	for (ll i=min(a, b);; ++i) {
		if (a<=i) {
			ll j=max(b, (n+i-1)/i);
			if (i*j<ans[0]*ans[1])
				ans={i, j};
		} else {
			ll j=max(a, (n+i-1)/i);
			if (i*j<ans[0]*ans[1])
				ans={j, i};
		}
		if (i*max({i, a, b})>=n)
			break;
	}
	cout << ans[0]*ans[1] << "\n" << ans[0] << " " << ans[1];
	return 0;
}