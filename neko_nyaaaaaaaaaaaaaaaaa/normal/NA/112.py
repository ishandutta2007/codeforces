#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll M = 1e9+7;

ll modpow(ll n, ll k) {
	if (k == 0) return 1;
	if (k == 1) return n;
	
	ll tmp = modpow(n, k/2);
	
	if (k % 2) {
		return (((tmp*tmp) % M) * n) % M;
	} else {
		return (tmp*tmp) % M;
	}
}

int main() {
	ios::sync_with_stdio(0);
	
	ll a, b, n, x;
	cin >> a >> b >> n >> x;
	
	ll ans = (modpow(a, n)*x) % M;
	
	if (a == 1) {ans = (ans + ((n % M)*b)%M)%M;} 
	else {
		ans = ans + (((modpow(a, n) - 1)*modpow(a - 1, M - 2)) % M) * b;
		ans %= M;
	}
	
	cout << ans;
	
	return 0;
}