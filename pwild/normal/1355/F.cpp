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

const ll N = 1e9, M = 5000;

vl pr;

map<ll,ll> factorize(ll x) {
	map<ll,ll> pf;
	for (ll p: pr) while (x%p == 0) x /= p, pf[p]++;
	return pf;
}

int main() {
	FOR(i,2,M) {
		bool ok = true;
		FOR(j,2,i) if (i%j == 0) ok = false;
		if (ok) pr.pb(i);
	}

	ll tc; cin >> tc;
	while (tc--) {
		ll j = 0, x = 1;
		FOR(k,0,17) {
			ll cur = 1;
			while (cur <= N*N/pr[j]) cur *= pr[j++];
			cout << "? " << cur << endl;
			
			ll g; cin >> g;
			x *= g;
		}
		
		FOR(k,0,5) {
			cout << "? " << x*x << endl;
			cin >> x;
		}

		map<ll,ll> pf = factorize(x);

		ll dx = 1;
		for (auto [p,e]: pf) dx *= e+1;

		ll p = pr[j], q = pr[j+1], r = pr[j+2], s = pr[j+3];
		assert(p*q*r*s*pr[j+4] > N);

		cerr << p << endl;

		ll dymax = 1;
		FOR(a,0,5) FOR(b,0,a+1) FOR(c,0,b+1) FOR(d,0,c+1) {
			ll y = 1, dy = (a+1)*(b+1)*(c+1)*(d+1);
			FOR(i,0,a) y = min(y*p, N+1);
			FOR(i,0,b) y = min(y*q, N+1);
			FOR(i,0,c) y = min(y*r, N+1);
			FOR(i,0,d) y = min(y*s, N+1);
			if (x*y > N) continue;
			dymax = max(dymax, dy);
		}
		
		ll lo = dx, hi = dx*dymax;
		
		TR(lo), TR(hi);

		ll res = 1;
		if (hi/lo <= 4) {
			res = min(2*lo,N);
		} else if (hi-lo <= 14) {
			res = (lo+hi)/2;
		} else {
			assert(0);
		}
		cout << "! " << res << endl;
	}
}