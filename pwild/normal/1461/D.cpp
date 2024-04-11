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

void rec(vl a, set<ll> &s) {
	s.insert(accumulate(all(a),0LL));
	if (sz(a) == 1) return;
	
	ll amin = *min_element(all(a));
	ll amax = *max_element(all(a));
	ll mid = (amin+amax)/2;

	vl b, c;
	for (ll x: a) (x <= mid ? b : c).pb(x);
	if (sz(b) && sz(c)) rec(b,s), rec(c,s);
}

void solve() {
	ll n, q;
	cin >> n >> q;

	vl a(n);
	FOR(i,0,n) cin >> a[i];

	set<ll> s;
	rec(a,s);

	while (q--) {
		ll x; cin >> x;
		cout << (s.count(x) ? "Yes" : "No") << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}