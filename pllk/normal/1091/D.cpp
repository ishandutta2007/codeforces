#include <iostream>

using namespace std;

#define N 1222333
#define M 998244353

typedef long long ll;

ll f[N];
ll g[N];

ll pot(int a, int b) {
	if (b == 0) return 1;
	ll u = pot(a,b/2);
	u = (u*u)%M;
	if (b%2 == 1) {
		u = u*a;
		u %= M;
	}
	return u;
}

ll inv(int x) {
	return pot(x,M-2);
}

ll ncr(int a, int b) {
	ll u = 1;
	u *= f[a];
	u %= M;
	u *= g[a-b];
	u %= M;
	u *= g[b];
	u %= M;
	return u;
}

int n;

int main() {
	f[0] = 1;
	g[0] = 1;
	for (int i = 1; i < N; i++) {
		f[i] = (f[i-1]*i)%M;
		g[i] = inv(f[i]);
	}
	cin >> n;
	ll u = f[n];
	for (int k = n-1; k >= 2; k--) {
		ll a = ncr(n,k);
		ll b = (f[k]-1)%M;
		if (b < 0) b += M;
		ll c = (a*b)%M;
		c = (c*f[n-k])%M;
		u += c;
		u %= M;
	}
	cout << u << "\n";
}