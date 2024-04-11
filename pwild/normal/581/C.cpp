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
	
	ll n, k; cin >> n >> k;
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	ll res = 0;
	FOR(i,0,n) res += a[i]/10;

	vl b(10);
	FOR(i,0,n) b[a[i] % 10]++;

	FORD(d,1,10) {
		ll take = min(k/(10-d), b[d]);
		res += take;
		b[0] += take;
		k -= (10-d)*take;
	}

	res += k/10;
	res = min(res,10*n);

	cout << res << endl;


}