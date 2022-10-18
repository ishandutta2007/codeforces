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
	
	ll n, m, k; cin >> n >> m >> k;
	
	if (k == 0 || k == n) {
		cout << -1 << endl;
		return 0;
	}
	
	vector<vector<pll>> adj(n);
	vb bak(n);
	FOR(i,0,m) {
		ll a, b, c; cin >> a >> b >> c;
		a--, b--;
		adj[a].eb(b,c), adj[b].eb(a,c);
	}
	FOR(i,0,k) {
		ll a; cin >> a;
		bak[a-1] = true;
	}
	ll res = oo;
	FOR(i,0,n) if (!bak[i]) {
		for (auto e: adj[i]) if (bak[e.xx]) res = min(res,e.yy);
	}
	if (res == oo) res = -1;
	cout << res << endl;
	
}