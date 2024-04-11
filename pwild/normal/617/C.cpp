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

ll dist(pll a, pll b) {
	ll dx = a.xx-b.xx, dy = a.yy-b.yy;
	return dx*dx + dy*dy;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n;
	pll p, q;
	cin >> n >> p.xx >> p.yy >> q.xx >> q.yy;

	vector<pll> a(n);
	FOR(i,0,n) cin >> a[i].xx >> a[i].yy;
	
	a.pb(p), a.pb(q);

	ll best = LLONG_MAX;
	FOR(i,0,n+2) {
		ll r1 = dist(p,a[i]);
		ll r2 = 0;
		FOR(j,0,n) if (dist(p,a[j]) > r1) r2 = max(r2,dist(q,a[j]));
		best = min(best,r1 + r2);
	}
	cout << best << endl;


}