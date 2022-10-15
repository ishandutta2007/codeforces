#include <iostream>

using namespace std;

typedef long long ll;
#define M 998244353

ll pot(ll a, ll b) {
	if (b == 0) return 1;
	ll u = pot(a,b/2);
	u = u*u%M;
	if (b%2 == 1) u = u*a%M;
	return u;
}

ll inv(ll x) {
	return pot(x,M-2);
}

ll ff[202020];

ll ncr(ll a, ll b) {
	ll u = ff[a];
	u = u*inv(ff[b])%M;
	u = u*inv(ff[a-b])%M;
	return u;
}

int main() {
	ff[0] = 1;
	for (int i = 1; i <= 200000; i++) ff[i] = ff[i-1]*i%M;
	int n;
	ll k;
	cin >> n >> k;
	if (k == 0) {
		cout << ff[n] << "\n";
	} else if (k > n-1) {
		cout << 0 << "\n";
	} else {
		int u = n-k;
		ll r = pot(u,n)*ncr(n,u)%M;
		int h = -1;
		for (int i = u-1; i >= 1; i--) {
			ll z = ncr(u,i)*pot(i,n)%M*ncr(n,u)%M;
			r += h*z;
			r = (r%M+M)%M;
			h = -h;
		}
		r = r*2%M;
		cout << r << "\n";
	}
}