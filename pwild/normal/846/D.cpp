#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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
	
	ll m, n, k, q;
	cin >> m >> n >> k >> q;

	ll tmin = -1, tmax = 1e9+1;

	vl x(q), y(q), t(q);
	FOR(i,0,q) {
		cin >> x[i] >> y[i] >> t[i];
		x[i]--, y[i]--;
	}

	while (tmax-tmin > 1) {
		ll tmid = (tmin+tmax)/2;
		
		vvl a(m,vl(n));
		FOR(i,0,q) if (t[i] <= tmid) a[x[i]][y[i]] = 1;
		
		vvl b(m+1,vl(n+1));
		FOR(i,1,m+1) FOR(j,1,n+1) {
			b[i][j] = a[i-1][j-1] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
		}
		
		bool broken = false;
		FOR(i,k,m+1) FOR(j,k,n+1) {
			if (b[i][j] - b[i][j-k] - b[i-k][j] + b[i-k][j-k] == k*k) broken = true;
		}

		if (broken) tmax = tmid; else tmin = tmid;
	}
	if (tmax > 1e9) tmax = -1;
	cout << tmax << endl;
}