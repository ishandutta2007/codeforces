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

const ll MOD = 1e9 + 7;

ll g(ll n, ll i, ll k) {
	ll res = 0;
	for (ll len = 1; len <= n; len += k-1) {
		FOR(a,0,i+1) {
			if (a+len > i && a+len <= n) res++;
		}
	}
	return res;
}

ll tri(ll n) {
	return (n*(n-1)/2) % MOD;
}

ll next_multiple(ll n, ll k) {
	return (n+k-1)/k;
}

ll f(ll n, ll i, ll k) {
	i = min(i,n-1-i);
	k--;
	
	ll s = next_multiple(i,k);
	ll t = next_multiple(n-i,k);
	ll u = next_multiple(n,k);

	ll a = tri(s)*k + s;
	ll b = (t-s)*(i+1) % MOD;
	ll c = (u-t)*(i-(t*k-(n-i))) - tri(u-t)*k;

	return (a+b+c) % MOD;
	return g(n,i,k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
/*	
	FOR(n,1,100) FOR(i,0,n) FOR(k,2,100) {
		if (f(n,i,k) != g(n,i,k)) {
			cout << n << " " << i << " " << k << " " << f(n,i,k) << " " << g(n,i,k) << endl;
		}
	}
*/

	ll n, k;
	cin >> n >> k;
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	vector<pll> v(n);
	FOR(i,0,n) v[i] = {-a[i],i};
	sort(all(v));

	set<ll> bounds = {-1,n};
	
	ll res = -accumulate(all(a),0LL);
	for (pll p: v) {
		ll i = p.yy;
		auto it = bounds.lower_bound(i);
		ll a = *prev(it), b = *it;
		res = (res - p.xx * f(b-a-1, i-a-1, k)) % MOD;
		bounds.insert(i);
	}
	if (res < 0) res += MOD;
	cout << res << endl;
}