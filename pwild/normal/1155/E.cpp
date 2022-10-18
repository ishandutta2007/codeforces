#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

const ll MOD = 1e6 + 3;
ll inv[50];

vl interpolate(vl f) {
	ll n = sz(f);
	FOR(i,1,n) FORD(j,i,n) {
		f[j] = (f[j]-f[j-1]) * inv[i] % MOD;
	}
	return f;
}

ll eval(vl p, ll x) {
	ll n = sz(p)-1, res = p[n];
	FORD(i,0,n) res = (p[i] + (x-i)*res) % MOD;
	return res;
}

int main() {
	inv[1] = 1;
	FOR(n,2,50) inv[n] = -(MOD/n)*inv[MOD%n] % MOD;
	
	FOR(n,1,50) assert((n*inv[n]-1) % MOD == 0);


	ll n = 20;
	vl f(n);
	FOR(x,0,n) {
		cout << "? " << x << endl;
		cin >> f[x];
	}
	
	vl p = interpolate(f);

	FOR(x,0,MOD) if (eval(p,x) == 0) {
		cout << "! " << x << endl;
		return 0;
	}
	cout << "! -1" << endl;
}