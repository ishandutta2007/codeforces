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

vvl solve(ll m, ll n) {
	if (m > n) {
		vvl a = solve(n,m), b(m,vl(n));
		FOR(i,0,m) FOR(j,0,n) b[i][j] = a[j][i];
		return b;
	}
	
	vvl a(m,vl(n));
	FOR(i,0,m) FOR(j,0,n) a[i][j] = (i+1)*(m+j+1);
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m, n;
	cin >> m >> n;
	
	if (m == 1 && n == 1) {
		cout << 0 << endl;
		return 0;
	}
	
	vvl a = solve(m,n);
	FOR(i,0,m) FOR(j,0,n) cout << a[i][j] << " \n"[j+1==n];
}