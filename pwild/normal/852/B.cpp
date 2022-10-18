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

const ll MOD = 1e9 + 7;

vl operator*(const vl &a, const vl &b) {
	ll m = sz(a);
	vl c(m);
	FOR(i,0,m) FOR(j,0,m) c[(i+j)%m] = (c[(i+j)%m] + a[i]*b[j]) % MOD;
	return c;
}

vl power(vl a, ll n) {
	ll m = sz(a);
	vl res(m,0);
	res[0] = 1;
	while (n) {
		if (n & 1) res = res*a;
		a = a*a;
		n /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, l, m;
	cin >> n >> l >> m;

	vl a(n), b(n), c(n);
	FOR(i,0,n) cin >> a[i];
	FOR(i,0,n) cin >> b[i];
	FOR(i,0,n) cin >> c[i];
	FOR(i,0,n) c[i] += b[i];
	
	vl aa(m), bb(m), cc(m);
	FOR(i,0,n) aa[a[i]%m]++;
	FOR(i,0,n) bb[b[i]%m]++;
	FOR(i,0,n) cc[c[i]%m]++;
	
	vl res = aa * power(bb,l-2) * cc;
	cout << res[0] << endl;
}