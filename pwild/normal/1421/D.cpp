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
		ll x, y;
		cin >> x >> y;
		vl val(6);
		FOR(i,0,6) cin >> val[i];
		vector<pll> dir = {{1,1},{0,1},{-1,0},{-1,-1},{0,-1},{1,0}};

		ll res = oo;
		FOR(i,0,6) FOR(j,i+1,6) {
			auto [a,c] = dir[i];
			auto [b,d] = dir[j];
			ll det = a*d-b*c;
			if (det == 0) continue;
			ll u = (d*x-b*y)/det, v = (a*y-c*x)/det;
			assert(a*u+b*v == x && c*u+d*v == y);
			if (u >= 0 && v >= 0) res = min(res, u*val[i] + v*val[j]);
		}
		cout << res << endl;
	}
}