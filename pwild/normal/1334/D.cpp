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
		ll n, a, b;
		cin >> n >> a >> b;
		a--;

		ll c = 0;
		vl res;
		FOR(k,1,n) {
			ll d = c + 2*(n-k);
			if (d > a && c < b) {
				FOR(i,k+1,n+1) {
					if (c >= a && c < b) res.pb(k);
					c++;
					if (c >= a && c < b) res.pb(i);
					c++;
				}
			}
			c = d;
		}
		if (c >= a && c < b) res.pb(1);
		
		assert(sz(res) == b-a);
		for (ll x: res) cout << x << " ";
		cout << endl;
	}

}