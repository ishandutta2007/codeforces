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

ll n;
vl a;

bool test(ll upper, bool pr = false) {
	set<ll> s(all(a));
	
	bool go = true;
	while (go) {
		go = false;
		ll x = *s.rbegin();
		if (x <= upper) break;
		FOR(k,1,32) {
			ll y = x >> k;
			if (y == 0 || y > upper || has(s,y)) continue;
			s.erase(x);
			s.insert(y);
			go = true;
			break;
		}
	}

	if (pr) {
		vl b(all(s));
		FOR(i,0,n) cout << b[i] << " \n"[i+1 == n];
	}
	return *s.rbegin() <= upper;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	a.resize(n);
	FOR(i,0,n) cin >> a[i];
	
	ll lo = 0, hi = 1e9;
	while (hi-lo > 1) {
		ll m = (lo+hi)/2;
		if (test(m)) hi = m;
		else lo = m;
	}
	test(hi,true);
}