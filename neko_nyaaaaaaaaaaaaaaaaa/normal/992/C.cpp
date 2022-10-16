#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll M = 1e9+7;

ll modpow(ll n, ll k) {
	if (k == 0) return 1;
	if (k == 1) return (n%M);
	
	ll tmp = modpow(n, k/2);
	tmp = (tmp*tmp)%M;
	if (k % 2) {
		return (tmp*n)%M;
	}
	return tmp;
} 

ll f(ll n, ll q) {
	return (((n*(n+1))%M)*q)%M;
}

int main() {
	ios::sync_with_stdio(0);
	
	ll x, k;
	cin >> x >> k;
	if (x == 0) {cout << 0; return 0;}
	x %= M;
	if (k == 0) {cout << (x*2)%M; return 0;}
	
	ll m = modpow(2, k);

	ll a = (m*x)%M;
	ll b = (m*(x-1))%M;
	
	ll q = modpow(2, M-2);
	ll ans1 = f(a, q) - f(b, q);
	if (ans1 < 0) ans1 += M;
	
	ll ans2 = modpow(modpow(2, k-1), M-2);
	cout << (ans1*ans2)%M;

	return 0;
}