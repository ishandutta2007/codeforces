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

	ll m, n; cin >> m >> n;

	vvl a(m,vl(n,0)), b(m,vl(n,0));
	FOR(i,0,m) FOR(j,0,n) {
		char c; cin >> c;
		a[i][j] = (c == 'B') ? 1 : -1;
	}
	
	ll res = 0;
	FORD(i,0,m) FORD(j,0,n) {
		a[i][j] += b[i][j];
		if (a[i][j]) {
			res++;
			b[i][j] -= a[i][j];
		}
		if (i) b[i-1][j] += b[i][j];
		if (j) b[i][j-1] += b[i][j];
		if (i && j) b[i-1][j-1] -= b[i][j];
	}
	cout << res << endl;

	
}