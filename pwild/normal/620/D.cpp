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
	
	ll m, n; cin >> m;
	vl a(m);
	FOR(i,0,m) cin >> a[i];
	cin >> n;
	vl b(n);
	FOR(i,0,n) cin >> b[i];
	
	ll sum = 0;
	FOR(i,0,m) sum += a[i];
	FOR(i,0,n) sum -= b[i];
	
	ll best = abs(sum);
	vector<pll> bestv;
	
	FOR(i,0,m) FOR(j,0,n) {
		ll sw = 2*(a[i]-b[j]);
		if (abs(sum - sw) < best) {
			best = abs(sum - sw);
			bestv = {{i,j}};
		}
	}
	
	vector<pair<ll,pll>> aa, bb;
	FOR(i,0,m) FOR(j,i+1,m) aa.eb(a[i]+a[j],pll(i,j));
	FOR(i,0,n) FOR(j,i+1,n) bb.eb(b[i]+b[j],pll(i,j));
	sort(all(aa)), sort(all(bb));

	ll i = 0, j = 0;
	while (i < sz(aa) && j < sz(bb)) {
		ll cur = sum - 2*(aa[i].xx - bb[j].xx);
		if (abs(cur) < best) {
			best = abs(cur);
			bestv = {{aa[i].yy.xx,bb[j].yy.xx},{aa[i].yy.yy,bb[j].yy.yy}};
		}
		if (cur > 0) i++; else j++;	
	}
	
	cout << best << endl;
	cout << sz(bestv) << endl;
	for (auto &p: bestv) cout << p.xx+1 << " " << p.yy+1 << endl;


}