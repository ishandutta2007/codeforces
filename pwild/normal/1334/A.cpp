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
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		bool ok = true;
		vl p(n), c(n);
		FOR(i,0,n) cin >> p[i] >> c[i];

		FOR(i,0,n) if (c[i] > p[i]) ok = false;
		FOR(i,0,n-1) if (c[i] > c[i+1]) ok = false;
		FOR(i,0,n-1) if (p[i] > p[i+1]) ok = false;
		FOR(i,0,n-1) if (p[i+1]-p[i] < c[i+1]-c[i]) ok = false;

		cout << (ok ? "YES" : "NO") << endl;
	}
}