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

vl solve(ll a, ll b, ll m) {
	if (a > b) return {};
	if (a == b) return {a};

	if (m == 1) {
		vl res = {a};
		a++;
		while (a <= b) {
			res.pb(a);
			if (a == b) return res;
			a *= 2;
		}
		return {};
	}

	FOR(t,0,oo) {
		ll lo = (a+1) << t, hi = (a+m) << t;
		if (lo > b) return {};
		if (hi < b) continue;

		ll diff = b - ((a+1) << t);
		
		vl k(t+1,1);
		
		if (b == hi) {
			FOR(i,0,t+1) k[i] = m;
		} else {
			ll q = diff/(m-1), r = diff%(m-1);
			assert(q < (1LL << t));
			k[t] += r;
			FOR(i,0,t) if (q & (1LL << i)) k[t-1-i] += m-1;
		}
		
		vl res(t+2);
		res[0] = a;
		FOR(i,1,t+2) {
			FOR(j,0,i) res[i] += res[j];
			res[i] += k[i-1];
		}
		return res;
	}
	return {};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll a, b, m;
		cin >> a >> b >> m;

		vl res = solve(a,b,m);
		if (sz(res)) {
			cout << sz(res);
			for (ll x: res) cout << " " << x;
			cout << endl;
		} else {
			cout << -1 << endl;
		}
	}
}