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

void factorize(ll n, vl &primes) {
	for (ll p = 2; p*p <= n; p++) if (n%p == 0) {
		primes.pb(p);
		while (n%p == 0) n /= p;
	}
	if (n > 1) primes.pb(n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	srand(14394);
	random_shuffle(all(a));
	
	vl primes;
	FOR(i,0,min(n,100LL)) factorize(a[i],primes);
	sort(all(primes));
	primes.erase(unique(all(primes)),end(primes));

	vl nprimes;
	for (ll p: primes) {
		ll count = 0;
		for (ll x: a) count += x%p == 0;
		if (2*count >= n) nprimes.pb(p);
	}
	primes = nprimes;
	assert(sz(primes) <= 22);
	
	unordered_map<ll,ll> dp;
	
	for (ll x: a) {
		ll y = 1;
		for (ll p: primes) while (x % (y*p) == 0) y *= p;
		dp[y]++;
	}
	
	for (ll p: primes) {
		unordered_map<ll,ll> ndp;
		for (auto [x,c]: dp) {
			for (ll y = x; ; y /= p) {
				ndp[y] += dp[x];
				if (y%p) break;
			}
		}
		dp = ndp;
	}
	
	ll res = 1;
	for (auto [x,c]: dp) if (2*c >= n) res = max(res,x);
	cout << res << endl;
}