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
	
	ll n, m; cin >> n >> m;
	vvl a(4,vl(n));
	FOR(i,0,n) {
		if (2*i+1 <= m) a[0][i] = 2*i+1;
		if (2*(n+i)+1 <= m) a[1][i] = 2*(n+i)+1;
		if (2*(n+i)+2 <= m) a[2][i] = 2*(n+i)+2;
		if (2*i+2 <= m) a[3][i] = 2*i+2;
	}
	vl b;
	FOR(i,0,n) {
		if (a[1][i]) b.pb(a[1][i]);
		if (a[0][i]) b.pb(a[0][i]);
		if (a[2][i]) b.pb(a[2][i]);
		if (a[3][i]) b.pb(a[3][i]);
	}
	assert(sz(b) == m);
	FOR(i,0,m) cout << b[i] << " \n"[i+1==m];


}