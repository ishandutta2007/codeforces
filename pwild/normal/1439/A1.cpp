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

		vvl a(m, vl(n));
		FOR(i,0,m) {
			string s; cin >> s;
			FOR(j,0,n) a[i][j] = s[j]-'0';
		}

		vvl res;
		auto add = [&](ll i1, ll j1, ll i2, ll j2, ll i3, ll j3) {
			res.pb({i1,j1,i2,j2,i3,j3});
			a[i1][j1] ^= 1;
			a[i2][j2] ^= 1;
			a[i3][j3] ^= 1;
		};

		FORD(i,2,m) {
			FORD(j,1,n) if (a[i][j]) {
				if (a[i][j-1]) {
					add(i,j,i,j-1,i-1,j);
				} else {
					add(i,j,i-1,j,i-1,j-1);
				}
			}
			if (a[i][0]) add(i,0,i-1,1,i-1,0);
		}
		FORD(j,2,n) {
			if (a[0][j] && a[1][j]) {
				add(0,j,1,j,0,j-1);
			} else if (a[0][j]) {
				add(0,j,0,j-1,1,j-1);
			} else if (a[1][j]) {
				add(1,j,0,j-1,1,j-1);
			}
		}

		ll k = a[0][0] + a[0][1] + a[1][0] + a[1][1];

		vector<pll> v;
		FOR(i,0,2) FOR(j,0,2) if (a[i][j] != k%2) v.eb(i,j);

		for (auto [i,j]: v) {
			vl cur;
			FOR(ii,0,2) FOR(jj,0,2) if (ii != i || jj != j) cur.pb(ii), cur.pb(jj);
			res.pb(cur);
		}

		cout << sz(res) << endl;
		for (auto v: res) {
			for (ll x: v) cout << x+1 << " ";
			cout << endl;
		}
	}
}