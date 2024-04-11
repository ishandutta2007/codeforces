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
	
	vl x(n), y(n);
	FOR(i,0,n) cin >> x[i] >> y[i];

	while (true) {
		FORD(i,0,n) x[i] -= x[0], y[i] -= y[0];

		vl res;
		FOR(i,0,n) if ((x[i]+y[i])%2) res.pb(i+1);
	
		if (sz(res)%n) {
			cout << sz(res) << endl;
			for (ll i: res) cout << i << " ";
			cout << endl;
			return 0;
		}

		vl nx(n), ny(n);
		FOR(i,0,n) {
			nx[i] = (x[i]+y[i])/2;
			ny[i] = (x[i]-y[i])/2;
		}
		x = nx, y = ny;
	}
}