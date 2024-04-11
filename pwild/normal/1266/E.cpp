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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n), b(n);
	FOR(i,0,n) cin >> a[i];

	ll total = accumulate(all(a),0LL);
	map<pll,ll> where;

	ll q; cin >> q;
	while (q--) {
		ll s, t, u;
		cin >> s >> t >> u;
		s--, u--;

		pll p(s,t);
		if (where.count(p)) {
			ll v = where[p];
			if (--b[v] < a[v]) total++;
			where.erase(p);
		}
		if (u >= 0) {
			where[p] = u;
			if (b[u]++ < a[u]) total--;
		}
		cout << total << '\n';
	}
}