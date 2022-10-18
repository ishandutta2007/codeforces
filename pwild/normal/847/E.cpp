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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	string s; cin >> s;
	
	vl a, b;
	FOR(i,0,n) if (s[i] == 'P') a.pb(i);
	FOR(i,0,n) if (s[i] == '*') b.pb(i);

	ll tmin = 0, tmax = 2*n+10;
	while (tmax-tmin > 1) {
		ll t = (tmin+tmax)/2;
		
		bool ok = true;
		ll j = 0;
		FOR(i,0,sz(a)) {
			if (j >= sz(b)) break;
			ll x = a[i], y = b[j];
			
			if (x-t > y) { ok = false; break; }

			ll ymax;
			if (y > x) ymax = x+t;
			else {
				ll u = x-y;
				ll v = (t-u)/2;
				if (2*u <= t) v = max(v,t-2*u);
				ymax = x+v;
			}
			while (j < sz(b) && b[j] <= ymax) j++;
		}
		if (j < sz(b)) ok = false;
		if (ok) tmax = t; else tmin = t;
	}
	cout << tmax << endl;
}