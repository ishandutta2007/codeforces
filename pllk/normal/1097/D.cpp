#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define M 1000000007

ll n;
int k;
vector<ll> v;

ll pot(ll a, int b) {
	if (b == 0) return 1;
	ll u = pot(a,b/2);
	u = (u*u)%M;
	if (b%2 == 1) u *= a;
	u %= M;
	return u;
}

ll inv(ll x) {
	return pot(x,M-2);
}

ll gg[100];

ll dd[11111][111];
ll uu[111][111];

int main() {
	gg[0] = 1;
	for (int i = 1; i < 100; i++) gg[i] = inv(i);

	cin >> n >> k;
	for (int x = 0; x <= 50; x++) {
		for (int i = 0; i <= x; i++) dd[0][i] = 0;
		dd[0][x] = 1;
		for (int j = 1; j <= k; j++) {
			ll s = 0;
			for (int i = x; i >= 0; i--) {
				s += dd[j-1][i]*gg[i+1];
				s %= M;
				dd[j][i] = s;
			}
		}
		for (int y = 0; y <= 50; y++) {
			uu[x][y] = dd[k][y];
		}
	}

	for (ll u = 2; u*u <= n; u++) {
		while (n%u == 0) {
			v.push_back(u);
			n /= u;
		}
	}
	if (n > 1) v.push_back(n);

	ll u = 1;
	int c = 0;
	int h = v.size();
	for (int i = 0; i < h; i++) {
		c++;
		if (i == h-1 || v[i] != v[i+1]) {
			ll s = 0;
			ll w = 1;
			for (int j = 0; j <= c; j++) {
				s += uu[c][j]*w;
				s %= M;
				w *= v[i];
				w %= M;
			}
			u *= s;
			u %= M;
			c = 0;
		}
	}
	cout << u << "\n";
}