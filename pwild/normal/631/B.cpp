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

	ll m, n, k; cin >> m >> n >> k;
	vl ci(m), cj(n), ti(m,oo), tj(n,oo);
	while (k--) {
		ll t, i, c;	cin >> t >> i >> c;
		if (t == 1) ci[i-1] = c, ti[i-1] = k;
		else cj[i-1] = c, tj[i-1] = k;
	}
	FOR(i,0,m) FOR(j,0,n) {
		if (ti[i] < tj[j]) cout << ci[i]; else cout << cj[j];
		if (j+1 == n) cout << "\n"; else cout << " ";
	}


}