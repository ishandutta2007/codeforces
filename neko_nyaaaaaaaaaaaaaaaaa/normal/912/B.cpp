#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int bitcount(ll n) {
	ll ans = 0;
	while (n) {
		ans++;
		n >>= 1;
	}
	return ans;
}

ll power(ll a, ll b) {
	ll ans = 1;
	for (ll i = 0; i < b; i++) {
		ans *= a;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	
	ll n;
	int k;
	cin >> n >> k;
	if (k == 1) {cout << n; return 0;}
	ll ans = power(2, bitcount(n)) - 1;
	cout << ans;
	
	return 0;
}