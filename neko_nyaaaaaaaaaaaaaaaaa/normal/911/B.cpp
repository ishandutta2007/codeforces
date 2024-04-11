#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	ll n, a, b;
	cin >> n >> a >> b;
	ll ans = 0;
	for (ll i = 1; i < n; i++) {
		ll tmpa = a/i;
		ll tmpn = n - i;
		ll tmpb = b/tmpn;
		if (min(tmpa, tmpb) > ans) {ans = min(tmpa, tmpb);}
	}
	cout << ans;
	
	
	return 0;
}