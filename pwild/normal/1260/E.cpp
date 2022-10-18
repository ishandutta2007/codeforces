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
	ll k = 0;
	while ((1 << k) != n) k++;
	
	vl a;
	bool seen = false;
	FOR(i,0,n) {
		ll x; cin >> x;
		if (x == -1) {
			seen = true;
		} else {
			if (!seen) x = 0;
			a.pb(x);
		}
	}
	reverse(all(a));

	ll res = 0;
	set<pll> values;
	
	ll i = 0;
	FORD(j,0,k) {
		values.emplace(a[i],i), i++;
		res += begin(values)->xx;
		values.erase(begin(values));
		FOR(t,1,1 << j) values.emplace(a[i],i), i++;
	}
	assert(i == n-1);
	
	cout << res << endl;

}