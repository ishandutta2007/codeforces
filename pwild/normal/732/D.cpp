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
	
	ll n, m; cin >> n >> m;
	vl d(n);
	FOR(i,0,n) cin >> d[i], d[i]--;
	vl a(m);
	FOR(i,0,m) cin >> a[i];
	
	ll rmin = 0, rmax = n+1;
	while (rmax - rmin > 1) {
		ll r = (rmin+rmax)/2;
		vector<pll> ev;
		vb mark(m);
		FORD(i,0,r) if (d[i] >= 0 && !mark[d[i]]) {
			mark[d[i]] = true;
			ev.eb(i,d[i]);
		}
		reverse(all(ev));
		bool ok = true;
		ll learnt = 0, lastx = -1;
		for (const auto &e: ev) {
			learnt += e.xx-1-lastx;
			learnt -= a[e.yy];
			if (learnt < 0) ok = false;
			lastx = e.xx;
		}
		FOR(i,0,m) if (!mark[i]) ok = false;
		if (ok) rmax = r; else rmin = r;
	}
	if (rmax == n+1) rmax = -1;
	cout << rmax << endl;
}