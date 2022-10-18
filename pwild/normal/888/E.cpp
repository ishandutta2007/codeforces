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

vl sums(vl a, ll m) {
	ll n = sz(a);
	vl res(1 << n);
	FOR(mask,0,1 << n) FOR(i,0,n) if (mask & (1 << i)) res[mask] += a[i];
	FOR(mask,0,1 << n) res[mask] %= m;
	sort(all(res));
	res.erase(unique(all(res)),end(res));
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	vl b(begin(a),begin(a)+(n/2)), c(begin(a)+(n/2),end(a));
	b = sums(b,m), c = sums(c,m);
	
	ll res = (b.back()+c.back()) % m;
	for (ll x: b) {
		auto it = lower_bound(all(c),m-x);
		if (it == begin(c)) continue;
		ll y = *prev(it);
		res = max(res,x+y);
	}
	cout << res << endl;
}