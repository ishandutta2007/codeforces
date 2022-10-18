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

vvl operator*(const vvl &a, const vvl &b) {
	ll n = sz(a);
	vvl res(n,vl(n));
	FOR(i,0,n) FOR(k,0,n) FOR(j,0,n) res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % MOD;
	return res;
}

vvl modExp(vvl a, ll k) {
	ll n = sz(a);
	vvl res(n,vl(n));
	FOR(i,0,n) res[i][i] = 1;
	while (k) {
		if (k & 1) res = res*a;
		a = a*a;
		k /= 2;
	}
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m, n, k, x; cin >> m >> n >> k >> x;

	vl cnt(10);
	FOR(i,0,m) {
		ll d; cin >> d;
		cnt[d]++;
	}

	vl dp(x);
	dp[0] = 1;

	vvl a(x,vl(x));
	FOR(j,0,x) FOR(d,0,10) {
		a[j][(10*j+d)%x] = (a[j][(10*j+d)%x] + cnt[d]) % MOD;
	}
	a = modExp(a,n);

	cout << a[0][k] << endl;





}