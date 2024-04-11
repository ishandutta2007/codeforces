#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vv;

#define M 998244353

vv mul(vv a, vv b) {
	vv c(4);
	c[0] = a[0]*b[0]+a[1]*b[2];
	c[0] %= M;
	c[1] = a[0]*b[1]+a[1]*b[3];
	c[1] %= M;
	c[2] = a[2]*b[0]+a[3]*b[2];
	c[2] %= M;
	c[3] = a[2]*b[1]+a[3]*b[3];
	c[3] %= M;
	return c;
}

vv pot(vv x, ll p) {
	if (p == 0) return {1,0,0,1};
	vv u = pot(x,p/2);
	u = mul(u,u);
	if (p%2 == 1) u = mul(u,x);
	return u;
}


int main() {
	ll n, m, l, r;
	cin >> n >> m >> l >> r;
	ll c0, c1;
	if (l%2 == 0) {
		c0 = (r-l)/2+1;
		c1 = (r-l+1)/2;
	} else {
		c0 = (r-l+1)/2;
		c1 = (r-l)/2+1;
	}
	vv v = {c0,c1,c1,c0};
	vv u = pot(v,n*m);
	ll z;
	if (n*m%2 == 0) {
		z = u[0];
	} else {
		z = u[0]+u[2];
	}
	z %= M;
	cout << z << "\n";
}