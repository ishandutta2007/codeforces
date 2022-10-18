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

const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	const ll n = 5e6 + 10;
	
	vl f(n);
	FOR(i,1,n) f[i] = i*(i-1)/2;
	FOR(j,2,n) {
		for (ll k = 1; k <= j && k*j < n; k++) {
			ll i = k*j;
			f[i] = min(f[i], j*k*(k-1)/2 + f[j]);
			f[i] = min(f[i], k*j*(j-1)/2 + f[k]);
		}
	}

	
	ll t, l, r;
	cin >> t >> l >> r;
	
//	FOR(i,1,30) cout << i << " " << f[i] << endl;

//	cerr << f[2] << " " << f[3] << " " << f[4] << endl;

	ll res = 0;
	FORD(i,l,r+1) res = (t*res + f[i]) % MOD;
	cout << res << endl;




}