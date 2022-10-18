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

vb is_max;
vvl ch;

pll dfs(ll i) {
	if (!sz(ch[i])) return {0,1};
	
	ll k = 0;
	vector<pll> a;
	for (ll j: ch[i]) {
		pll p = dfs(j);
		k += p.yy, a.pb(p);
	}
	
	if (is_max[i]) {
		ll best = oo;
		for (pll p: a) best = min(best,p.yy-p.xx);
		return {k-best,k};
	} else {
		ll best = 0;
		for (pll p: a) best += p.xx;
		return {best,k};
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	is_max.resize(n);
	FOR(i,0,n) {
		ll x; cin >> x;
		is_max[i] = x;
	}
	
	ch.resize(n);
	vl p(n,-1);
	FOR(i,1,n) cin >> p[i], p[i]--;
	FOR(i,1,n) ch[p[i]].pb(i);

	cout << dfs(0).xx+1 << endl;
}