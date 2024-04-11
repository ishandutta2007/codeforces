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
/*	
	vl p = {0,1,2,3,4,5,6};
	do {
		vl q(sz(p));
		ll hi = -1;
		FOR(i,0,sz(p)) {
			hi = max(hi,p[i]);
			if (i == sz(p)-1 || p[i+1] > hi) q[p[i]] = hi;
			else q[p[i]] = p[i+1];
		}
		if (p == q) {
			FOR(i,0,sz(p)) cout << p[i] << " ";
			cout << endl;
		}
	} while (next_permutation(all(p)));
*/
	
	ll n, k; cin >> n >> k;
	k--;

	vl fib = {1,1};
	while (fib[sz(fib)-1] < 3e18) fib.pb(fib[sz(fib)-1]+fib[sz(fib)-2]);

	ll m = sz(fib);

	vb take(m);
	
	FORD(i,0,m) if (k >= fib[i]) {
		take[i] = true;
		k -= fib[i];
	}
	
	vl p(n);
	FOR(i,0,n) p[i] = i+1;
	FOR(i,0,m) if (take[i]) {
		ll j = n-i-1;
		swap(p[j],p[j+1]);
	}
	FOR(i,0,n-1) cout << p[i] << " ";
	cout << p[n-1] << endl;

}