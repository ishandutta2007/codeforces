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

ll g_odd(ll n) {
	if (n == 0 || n == 2) return 0;
	if (n >= 5 && n % 2 == 1) return 0;
	if (n == 1) return 1;
	ll k = 0;
	while (n % 2 == 0) k++, n /= 2;
	if (k % 2 == 0 && n == 3) return 1;
	if (k % 2 == 1 && n/2 != 1) return 1;
	return 2;
}

ll g_even(ll n) {
	if (n <= 2) return n;
	if (n % 2 == 0) return 1;
	return 0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
/*	
	ll N = 100000;
	vl g(N);
	FOR(n,1,N) {
		set<ll> s = {g[n-1]};
		if (n % 2 == 0) s.insert(g[0]);
		while (has(s,g[n])) g[n]++;
		if (g[n] != g_even(n)) cout << n << endl;
//		if (n % 4 == 0 && g[n] < 2) cout << bitset<10>(n/4).to_string() << endl;
	}
	return 0;
*/
	ll n, k; cin >> n >> k;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	ll res = 0;
	FOR(i,0,n) res ^= (k % 2) ? g_odd(a[i]) : g_even(a[i]);
	cout << (res ? "Kevin" : "Nicky") << endl;


}