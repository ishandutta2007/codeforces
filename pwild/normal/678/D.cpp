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

vvl operator*(const vvl &b, const vvl &c) {
	vvl a(2,vl(2));
	FOR(i,0,2) FOR(j,0,2) FOR(k,0,2) a[i][j] = (a[i][j] + b[i][k]*c[k][j]) % MOD;
	return a;
}

vvl power(vvl a, ll n) {
	vvl res = {{1,0},{0,1}};
	while (n) {
		if (n & 1) res = res*a;
		a = a*a;
		n /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll a, b, n, x; cin >> a >> b >> n >> x;
	
	vvl p = {{a,b},{0,1}};
	p = power(p,n);
	cout << (p[0][0]*x + p[0][1]) % MOD << endl;


}