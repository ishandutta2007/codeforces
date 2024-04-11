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

const ll MOD = 1e9 + 7;

ll exp_mod(ll a, ll n) {
	ll res = 1;
	for (; n; n /= 2) {
		if (n&1) res = res*a % MOD;
		a = a*a % MOD;
	}
	return res;
}

map<ll,ll> factorize(ll n) {
	map<ll,ll> res;
	for (ll d = 2; d*d <= n; d++) {
		if (n%d) continue;
		while (n%d == 0) n /= d, res[d]++;
	}
	if (n > 1) res[n]++;
	return res;
}

vvl operator*(vvl a, vvl b) {
	ll n = sz(a);
	vvl c(n,vl(n));
	FOR(i,0,n) FOR(k,0,n) FOR(j,0,n) {
		c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % (MOD-1);
	}
	return c;
}

vvl power(vvl a, ll k) {
	ll n = sz(a);
	vvl res(n,vl(n));
	FOR(i,0,n) res[i][i] = 1;
	for (; k; k /= 2) {
		if (k&1) res = res*a;
		a = a*a;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vl a(3);
	ll n, c;
	cin >> n >> a[0] >> a[1] >> a[2] >> c;
	
	vector<map<ll,ll>> afac(3);
	FOR(k,0,3) afac[k] = factorize(a[k]);
	
	auto cfac = factorize(c);
	
	set<ll> primes;
	FOR(k,0,3) for (pll pr: afac[k]) primes.insert(pr.xx);
	for (pll pr: cfac) primes.insert(pr.xx);
	
	ll res = 1;
	for (ll p: primes) {
		vvl A = {
			{1,1,1,2,0},
			{1,0,0,0,0},
			{0,1,0,0,0},
			{0,0,0,1,0},
			{0,0,0,0,1}
		};
		A[3][4] = cfac[p];
		
		A = power(A,n-1);
		
		vl b = {afac[2][p], afac[1][p], afac[0][p], cfac[p], 1};
		
		vl c(5);
		FOR(i,0,5) FOR(j,0,5) c[i] = (c[i] + A[i][j]*b[j]) % (MOD-1);

//		cerr << p << endl;
//		FOR(i,0,5) cerr << b[i] << " \n"[i==4];
//		FOR(i,0,5) cerr << c[i] << " \n"[i==4];
		
		res = res * exp_mod(p,c[2]) % MOD;
	}
	cout << res << endl;
}