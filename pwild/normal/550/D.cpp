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
	
	ll k; cin >> k;
	if (k % 2 == 0) {
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";
	
	ll N = (k-1)*(k+1) + 2;
	vector<pll> edges;

	ll n = 0;
	FOR(i,0,k-1) {
		FOR(a,1,k) FOR(b,a+1,k) edges.eb(n + a,n + b);
		n += k-1;
	}
	FOR(i,0,2*(k-1)) {
		FOR(a,1,k) edges.eb((k-1)*(i/2) + a,n + i + 1);
	}
	ll nn = n + 2*(k-1);
	FOR(i,0,2*(k-1)) {
		edges.eb(n+i+1,nn + 1 + (i >= (k-1)));
	}
	edges.eb(N-1,N);

	cout << N << " " << sz(edges) << "\n";

	for (const auto &e: edges) cout << e.xx << " " << e.yy << "\n";

}