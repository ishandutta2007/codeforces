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
	
	ll n, k; cin >> n >> k;
	vl a(n), b(n);
	FOR(i,0,n) cin >> a[i];
	FOR(i,0,n) cin >> b[i];
	
	ll rmin = 0, rmax = 2e9 + 10;
	while (rmax-rmin > 1) {
		ll r = (rmin+rmax)/2;
		ll magic = k;
		FOR(i,0,n) {
			ll need = r*a[i] - b[i];
			if (need > 0) magic -= need;
			if (magic < 0) break;
		}
		if (magic >= 0) rmin = r; else rmax = r;
	}
	cout << rmin << endl;



}