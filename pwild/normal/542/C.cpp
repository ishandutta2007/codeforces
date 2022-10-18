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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b/gcd(a,b)); }

ll n;

vl operator*(const vl &a, const vl &b) {
	vl res(n);
	FOR(i,0,n) res[i] = a[b[i]];
	return res;
}

vl iter(vl a, ll k) {
	vl res(n);
	FOR(i,0,n) res[i] = i;
	while (k) {
		if (k % 2) res = res * a;
		a = a * a;
		k /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vl f(n);
	FOR(i,0,n) cin >> f[i], f[i]--;

	ll res = 1;
	vl mark(n,-1);
	FOR(i,0,n) if (mark[i] < 0) {
		ll x = i;
		do mark[x] = i, x = f[x]; while (mark[x] < 0);
		ll cyc = 0, y = x;
		if (mark[x] != i) continue;
		do {
			cyc++, y = f[y]; 
		} while (y != x);
		res = lcm(res,cyc);
	}
	FOR(k,1,n+2) {
		bool ok = true;
		vl gg = iter(f,2*k*res), g = iter(f,k*res);
		FOR(i,0,n) if (g[i] != gg[i]) ok = false;
		if (ok) {
			cout << k*res << endl;
			return 0;
		}
	}



}