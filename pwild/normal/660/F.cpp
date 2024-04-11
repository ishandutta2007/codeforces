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

double intersect(pll a, pll b) {
	return double(b.yy-a.yy)/(a.xx-b.xx);
}

bool bad(pll a, pll b, pll c) {
	return (b.xx-a.xx)*(c.yy-b.yy) > (c.xx-b.xx)*(b.yy-a.yy);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl t(n), tsum(n+1), ttsum(n+1);
	FOR(i,0,n) cin >> t[i];
	FOR(i,0,n) tsum[i+1] = tsum[i] + t[i];
	FOR(i,0,n) ttsum[i+1] = ttsum[i] + (i+1)*t[i];
	
	ll res = 0;
	vector<pair<double,pll>> v;
	v.pb({-1e100,{0,0}});
	FOR(i,1,n+1) {
		pair<double,pll> q = {-tsum[i],{0,0}};
		pll p = (--lower_bound(all(v),q))->yy;
		res = max(res,ttsum[i] - p.xx*tsum[i] + p.yy);
		v.pb({0,{i,i*tsum[i] - ttsum[i]}});
		while (sz(v) >= 3 && bad(v[sz(v)-3].yy,v[sz(v)-2].yy,v[sz(v)-1].yy))
			v.erase(end(v)-2);
		v[sz(v)-1].xx = intersect(v[sz(v)-2].yy,v[sz(v)-1].yy);
	}
	cout << res << endl;
}