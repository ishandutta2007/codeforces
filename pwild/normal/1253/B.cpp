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

void fail() {
	cout << -1 << endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	set<ll> active, done;
	vl res;
	FOR(i,0,n) {
		ll x; cin >> x;
		if (x > 0) {
			if (active.count(x)) fail();
			if (done.count(x)) fail();
			active.insert(x);
		} else {
			x = -x;
			if (!active.count(x)) fail();
			active.erase(x);
			done.insert(x);
		}
		if (active.empty()) {
			res.pb(2*sz(done));
			done.clear();
		}
	}
	
	if (sz(active) || sz(done)) fail();

	cout << sz(res) << endl;
	for (ll x: res) cout << x << " ";
	cout << endl;
}