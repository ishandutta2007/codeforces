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
		ll m, n;
		cin >> m >> n;
		vvl a(m,vl(n));
		FOR(i,0,m) FOR(j,0,n) cin >> a[i][j];
		
		ll r = 0, c = 0;
		FOR(i,0,m) {
			ll s = 0;
			FOR(j,0,n) s += a[i][j];
			if (s == 0) r++;
		}
		FOR(j,0,n) {
			ll s = 0;
			FOR(i,0,m) s += a[i][j];
			if (s == 0) c++;
		}
		
		cout << (min(c,r) % 2 == 0 ? "Vivek" : "Ashish") << endl;
	}

}