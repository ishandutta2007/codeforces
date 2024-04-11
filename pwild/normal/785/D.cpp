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

const ll N = 5e5, MOD = 1e9+7;
ll inv[N], fac[N], invfac[N];

ll binom(ll n, ll k) {
	if (k < 0 || k > n) return 0;
	return fac[n] * invfac[k] % MOD * invfac[n-k] % MOD; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	inv[1] = 1;
	FOR(n,2,N) inv[n] = (MOD - inv[MOD%n] * (MOD/n) % MOD) % MOD;

	fac[0] = 1;
	FOR(n,1,N) fac[n] = n*fac[n-1] % MOD;
	
	invfac[0] = 1;
	FOR(n,1,N) invfac[n] = inv[n] * invfac[n-1] % MOD;
	
	string a; cin >> a;
	ll n = sz(a);
	
	vl op(n+1), cl(n+1);
	FOR(i,0,n) op[i+1] = op[i] + (a[i] == '(');
	FORD(i,0,n) cl[i] = cl[i+1] + (a[i] == ')');
	
	ll res = 0;
	FOR(i,0,n) if (a[i] == '(') {
		ll a = op[i], b = cl[i+1];
		res = (res + binom(a+b,a+1)) % MOD;
	}
	cout << res << endl;
}