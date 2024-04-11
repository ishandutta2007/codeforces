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

const ll MOD = 998244353;

vvl operator*(vvl a, vvl b) {
	vvl c(2,vl(2));
	FOR(i,0,2) FOR(k,0,2) FOR(j,0,2) {
		c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % MOD;
	}
	return c;
}

vvl power(vvl a, ll n) {
	vvl res = {{1,0},{0,1}};
	while (n) {
		if(n%2) res = res*a;
		a = a*a;
		n /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m, n, a, b;
	cin >> m >> n >> a >> b;
	
	vvl A;

	if (m%2 && n%2) {
		A = {{b-a+1,0},{0,1}};	
	} else {
		ll u = (b-a+1)/2, v = u;
		if (b%2 == a%2) (a%2 ? v : u)++;
		A = {{u,v},{v,u}};
	}
	A = power(A, m*n);

	cout << A[0][0] << endl;
}