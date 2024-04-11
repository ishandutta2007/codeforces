#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll n, ll m, ll k) {
	ll ans = 0;
	k--;
	
	for (ll i = 1; i <= n; i++) {
		ans += min(m, k/i);
	}
	
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ll n, m, k;
	cin >> n >> m >> k;
	
	ll lo = 1, hi = 1e18;
	while (lo < hi) {
		ll mid = (lo + hi)/2;
		
		ll f = solve(n, m, mid);
		
		if (f < k) {
			lo = mid+1;
		} else {
			hi = mid;
		}
	}
	cout << lo - 1;
	
	return 0;
}