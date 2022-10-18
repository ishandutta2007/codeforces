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
		vl m(n), p(n);
		FOR(i,0,n) cin >> m[i] >> p[i];

		vl is(n);
		iota(all(is),0);
		sort(all(is), [&](ll i, ll j) {
			if (m[i] != m[j]) return m[i] < m[j];
			return p[i] > p[j];
		});
		
		multiset<ll> costs;
		ll res = 0, k = 0;
		FORD(j,0,n) {
			ll i = is[j];
			while (m[i]-k > j) {
				k++;
				res += *begin(costs);
				costs.erase(begin(costs));
			}
			costs.insert(p[i]);
		}
		cout << res << endl;
	}
}