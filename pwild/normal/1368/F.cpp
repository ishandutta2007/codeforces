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

	auto f = [&](ll k) { return n - k - (n+k-1)/k + 1; };

	ll k = 1;
	FOR(j,1,n+1) if (f(j) > f(k)) k = j; 
	
	set<ll> on, off;
	FOR(i,0,n) if (i%k != 0) off.insert(i);

	cerr << k << " " << f(k) << endl;

	while (sz(on) < f(k)) {
		assert(sz(off) >= k);
		
		cout << k;
		FOR(i,0,k) {
			ll x = *begin(off);
			off.erase(x), on.insert(x);
			cout << " " << x+1;
		}
		cout << endl;
		
		ll j; cin >> j; j--;
		FOR(i,0,k) {
			ll y = (j+i)%n;
			if (!on.count(y)) continue;
			on.erase(y), off.insert(y);
		}
	}
	cout << 0 << endl;
}