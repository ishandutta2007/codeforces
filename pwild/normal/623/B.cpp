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

void add_divisors(ll n, set<ll> &s) {
	for (ll i = 1; i*i <= n; i++) if (n % i == 0) {
		if (i > 1) s.insert(i);
		if (n/i > 1) s.insert(n/i);
	}
}

bool prime(ll n) {
	if (n <= 1) return false;
	for (ll i = 2; i*i <= n; i++) if (n % i == 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, a, b; cin >> n >> a >> b;
	vl x(n);
	FOR(i,0,n) cin >> x[i];
	
	set<ll> s;
	FOR(dx,-1,2) add_divisors(x[0]+dx,s), add_divisors(x[n-1]+dx,s);

	ll res = oo;
	for (ll g: s) if (prime(g)) {
		vl dpl(n+1), dpr(n);
		dpl[0] = 0;
		FOR(i,0,n) {
			dpl[i+1] = dpl[i];
			if (x[i] % g == 0) continue;
			if ((x[i]+1) % g == 0 || (x[i]-1) % g == 0) dpl[i+1] += b;
			else dpl[i+1] = oo;
		}
		res = min(res,dpl[n]);
		FOR(i,1,n) dpl[i] = min(dpl[i],a+dpl[i-1]);
		dpr[n-1] = 0;
		FORD(i,1,n) {
			dpr[i-1] = dpr[i];
			if (x[i] % g == 0) continue;
			if ((x[i]+1) % g == 0 || (x[i]-1) % g == 0) dpr[i-1] += b;
			else dpr[i-1] = oo;
		}
		FORD(i,0,n-1) dpr[i] = min(dpr[i],a+dpr[i+1]);
		res = min(res,dpl[n]);
		FOR(i,0,n) res = min(res,dpl[i]+a+dpr[i]);
	}
	cout << res << endl;
}