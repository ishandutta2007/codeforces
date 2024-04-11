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
	
	ll h; cin >> h;

	vl a(h+1);
	FOR(i,0,h+1) cin >> a[i];

	bool unique = true;
	FOR(i,0,h) if (a[i] > 1 && a[i+1] > 1) unique = false;

	if (unique) {
		cout << "perfect" << endl;
		return 0;
	}
	cout << "ambiguous" << endl;
	
	vl v, w;

	ll x = 0, y = 1;
	FOR(i,0,h+1) {
		ll z = y + a[i];
		FOR(j,0,a[i]) v.pb(x);
		FOR(j,0,a[i]) w.pb(x + j%(y-x));
		x = y, y = z;
	}
	
	for (ll x: v) cout << x << " ";
	cout << endl;
	for (ll x: w) cout << x << " ";
	cout << endl;







}