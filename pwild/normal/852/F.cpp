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

ll mod_exp(ll a, ll n, ll m) {
	ll res = 1%m;
	while (n) {
		if (n & 1) res = res*a % m;
		a = a*a % m;
		n /= 2;
	}
	return res;
}

ll mod_inv(ll a, ll p) { return mod_exp(a,p-2,p); }

ll mult_order(ll a, ll m) {
	a %= m;
	for (ll b = a, k = 1; ; b = b*a % m, k++) if (b == 1) return k;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, a, q; cin >> n >> m >> a >> q;

	ll p = mult_order(a,q);
	
	ll bin = 1, sbin = 0;
	
	vl res(n);
	FOR(k,0,n) {
		sbin = (sbin + bin) % p;
		res[k] = mod_exp(a,sbin,q);
		if (k > m) bin = 0;
		bin = bin * (m-k) % p * mod_inv(k+1,p) % p;
	}

	reverse(all(res));
	FOR(i,0,n) cout << res[i] << " \n"[i+1==n];
}