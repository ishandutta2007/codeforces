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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k;
	cin >> n >> k;

	vl a(n);
	FOR(i,0,n) cin >> a[i];
	sort(all(a), greater<ll>());
	
	vl c(k+1);
	FOR(i,0,k) cin >> c[i];

	vl b;
	FORD(i,0,k) FOR(x,c[i+1],c[i]) b.pb(i+1);

	vvl res;
	auto solve = [&](ll m) {
		res.assign(m, vl());
		FOR(i,0,n) {
			vl &v = res[i%m];
			if (sz(v) >= sz(b)) return false;
			if (b[sz(v)] < a[i]) return false;
			v.pb(a[i]);
		}
		return true;
	};

	ll mmin = 0, mmax = n;
	while (mmax-mmin > 1) {
		ll m = (mmin+mmax)/2;
		if (solve(m)) mmax = m; else mmin = m;
	}
	assert(solve(mmax));
	
	cout << sz(res) << endl;
	for (auto v: res) {
		cout << sz(v);
		for (ll x: v) cout << " " << x;
		cout << endl;
	}
}