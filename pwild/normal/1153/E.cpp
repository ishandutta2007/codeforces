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

ll query(ll i1, ll j1, ll i2, ll j2) {
	cout << "? " << i1+1 << " " << j1+1 << " " << i2 << " " << j2 << endl;
	ll ans; cin >> ans;
	return ans % 2;
}

void solve(ll i1, ll j1, ll i2, ll j2) {
	cout << "! " << i1+1 << " " << j1+1 << " " << i2+1 << " " << j2+1 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	vb oddh(n-1), oddv(n-1);
	FOR(i,0,n-1) {
		oddv[i] = query(0,0,n,i+1);
		oddh[i] = query(0,0,i+1,n);
	}
	
	ll imin = oo, imax = -oo;
	ll jmin = oo, jmax = -oo;

	FOR(i,0,n-1) if (oddh[i]) imin = min(imin,i);
	FOR(i,0,n-1) if (oddh[i]) imax = max(imax,i);
	FOR(j,0,n-1) if (oddv[j]) jmin = min(jmin,j);
	FOR(j,0,n-1) if (oddv[j]) jmax = max(jmax,j);
	
	if (imin < oo && jmin < oo) {
		if (query(imin,jmin,imin+1,jmin+1)) {
			solve(imin,jmin,imax+1,jmax+1);
		} else {
			solve(imin,jmax+1,imax+1,jmin);
		}
	} else if (imin < oo) {
		ll lo = 0, hi = n;
		while (hi-lo > 1) {
			ll cur = (lo+hi)/2;
			if (query(0,0,imin+1,cur)) hi = cur;
			else lo = cur;
		}
		solve(imin,lo,imax+1,lo);
	} else if (jmin < oo) {
		ll lo = 0, hi = n;
		while (hi-lo > 1) {
			ll cur = (lo+hi)/2;
			if (query(0,0,cur,jmin+1)) hi = cur;
			else lo = cur;
		}
		solve(lo,jmin,lo,jmax+1);
	} else {
		assert(0);
	}
}