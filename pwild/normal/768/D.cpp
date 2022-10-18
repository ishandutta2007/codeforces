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

const ll N = 10000;
double p[N][1010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, q; cin >> n >> q;
	p[0][0] = 1;
	
	FOR(i,0,N-1) FOR(j,0,n+1) {
		p[i+1][j] += j*p[i][j]/n;
		p[i+1][j+1] += (n-j)*p[i][j]/n;
	}
	
	while (q--) {
		ll t; cin >> t;
		double q = t/2000.0;
		ll res = 0;
		while (p[res][n] < q) res++;
		cout << res << endl;
	}

}