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

ll solve(vl a, ll p) {
	ll n = sz(a);
	FOR(i,0,n) a[i] %= p;
	
	vl b(n);
	ll m = 0;
	FOR(i,0,n) {
		m += a[i];
		if (m > p/2) {
			b[i] = p;
			m -= p;
		}
	}
	assert(m == 0);
	
	ll res = 0;
	FOR(i,0,n) {
		m += a[i]-b[i];
		res += abs(m);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	ll m = accumulate(all(a),0LL);
	
	if (m == 1) {
		cout << -1 << endl;
		return 0;
	}

	vl primes;
	for (ll p = 2; p*p <= m; p++) if (m%p == 0) {
		primes.pb(p);
		while (m%p == 0) m /= p;
	}
	if (m > 1) primes.pb(m);
	
	ll res = oo;
	for (ll p: primes) {
		res = min(res, solve(a,p));
	}
	cout << res << endl;
}