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

void compress(vector<pair<ll,char>> &v) {
	ll x = 0; char y = v[0].yy;
	vector<pair<ll,char>> w;
	for (auto p: v) {
		if (p.yy == y) x += p.xx;
		else w.eb(x,y), x = p.xx, y = p.yy;
	}
	w.eb(x,y);
	v = w;
}

int main() {
	
	ll n, m;
	scanf("%lld%lld",&n,&m);

	vector<pair<ll,char>> w(n), v(m);
	FOR(i,0,n) scanf("%lld-%c",&w[i].xx,&w[i].yy);
	FOR(i,0,m) scanf("%lld-%c",&v[i].xx,&v[i].yy);
	
	compress(v), m = sz(v);
	compress(w), n = sz(w);
	
//	FOR(i,0,n) cout << w[i].xx << " " << w[i].yy << endl;

	if (m == 1) {
		ll res = 0;
		FOR(i,0,n) if (w[i].yy == v[0].yy && w[i].xx >= v[0].xx) res += w[i].xx - v[0].xx + 1;
		cout << res << endl;
		return 0;
	}
	if (m == 2) {
		ll res = 0;
		FOR(i,0,n-1) if (w[i].yy == v[0].yy && w[i].xx >= v[0].xx &&
						 w[i+1].yy == v[1].yy && w[i+1].xx >= v[1].xx) res++;
		cout << res << endl;
		return 0;
	}
	
	vector<pair<ll,char>> vi(m-2);
	FOR(i,0,m-2) vi[i] = v[i+1];
	
	ll res = 0;
	vl prefix (m-2);
	ll mm = prefix[0] = 0;
	FOR(i,1,m-2) {
		while (mm > 0 && vi[mm] != vi[i]) mm = prefix[m-1];
		if (vi[mm] == vi[i]) mm++;
		prefix[i] = mm;
	}
	mm = 0;
	FOR(i,0,n) {
		while (mm > 0 && vi[mm] != w[i]) mm = prefix[mm-1];
		if (vi[mm] == w[i]) mm++;
		if (mm == m-2) {
			ll j = i-mm+1;
			if (j > 0 && w[j-1].yy == v[0].yy && w[j-1].xx >= v[0].xx &&
				i+1 < n && w[i+1].yy == v[m-1].yy && w[i+1].xx >= v[m-1].xx) res++;
			mm = prefix[mm-1];
		}
	}
	cout << res << endl;
}