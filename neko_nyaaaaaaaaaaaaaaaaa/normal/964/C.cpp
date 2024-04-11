#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll M = 1000000009;

ll modpow(ll n, ll k) {
	if (k == 0) return 1;
	if (k == 1) return n;
	ll tmp = modpow(n, k/2);
	if (k % 2) {
		return ((tmp*tmp)%M*n)%M; 
	}
	return (tmp*tmp)%M;
}

int main() {
	ios::sync_with_stdio(0);
	
	ll M = 1e9+9;
	
	ll n, a, b, k;
	cin >> n >> a >> b >> k;
	string s;
	cin >> s;
	
	ll sum = 0;
	for (ll i = 0; i < k; i++) {
		ll ss = (modpow(a, n-i)*modpow(b, i))%M;
		if (s[i] == '+') {
			sum = (sum + ss)%M;
		} else {
			sum = (sum - ss)%M;
		}
	}
	
	ll diff = (modpow(modpow(a, k), M-2) * modpow(b, k)) % M;
	
	ll ans = (sum * (modpow(diff, (n+1)/k) - 1)) % M; 
	if (ans < 0) ans += M;
	
	ans = (ans * modpow((diff - 1 + M * M) % M, M-2)) % M;
	
	if (diff == 1) {
		ans = (sum * ((n + 1) / k)) % M;
	}
	
	if (ans < 0) ans += M;
	
	cout << ans;
	
	return 0;
}