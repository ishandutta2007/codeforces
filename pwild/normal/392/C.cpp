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

const ll P = 1e9 + 7;

vvl operator*(const vvl &a, const vvl &b) {
	ll n = sz(a);
	vvl c(n,vl(n));
	FOR(i,0,n) FOR(k,0,n) FOR(j,0,n) c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % P;
	return c;
}

vvl power(vvl a, ll k) {
	ll n = sz(a);
	vvl res(n,vl(n));
	FOR(i,0,n) res[i][i] = 1;
	while (k) {
		if (k % 2) res = res*a;
		a = a*a;
		k /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vvl b(50,vl(50));
	FOR(n,0,50) {
		b[n][0] = b[n][n] = 1;
		FOR(k,1,n) b[n][k] = (b[n-1][k-1] + b[n-1][k]) % P;
	}

	ll n, k; cin >> n >> k;

	ll N = 2*k + 3;
	vvl a(N,vl(N));
	FOR(i,0,k+1) FOR(j,0,i+1) {
		a[i][j] = b[i][j];
		a[i][k+1+j] = b[i][j] * ((1LL << (i-j)) % P) % P;
	}
	FOR(i,0,k+1) a[k+1+i][i] = 1;
	a[2*k+2][k] = a[2*k+2][2*k+2] = 1;

	a = power(a,n+1);

	vl v(N);
	FOR(i,0,k+2) v[i] = 1;


	cout << a[N-1][0] << endl;
}