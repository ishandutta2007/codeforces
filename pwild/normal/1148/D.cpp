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

struct item {
	ll a, b, i;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	
	vector<item> v, w;
	FOR(i,0,n) {
		ll a, b;
		cin >> a >> b;
		if (a < b) v.pb({a,b,i+1});
		else w.pb({a,b,i+1});
	}

	if (sz(v) > sz(w)) {
		sort(all(v),[&](item s, item t) { return s.b > t.b; });
		cout << sz(v) << endl;
		for (auto it: v) cout << it.i << " ";
		cout << endl;
	} else {
		sort(all(w),[&](item s, item t) { return s.b < t.b; });
		cout << sz(w) << endl;
		for (auto it: w) cout << it.i << " ";
		cout << endl;
				
	}

}