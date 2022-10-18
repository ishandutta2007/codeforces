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

typedef bitset<10010> bs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m, n;
	cin >> m >> n;
	vector<bs> b(2*m);
	FOR(i,0,m) {
		ll k; cin >> k;
		while (k--) {
			ll x; cin >> x;
			b[i][x-1] = 1;
		}
		b[2*m-1-i] = ~b[i];
	}
	
	vvl adj(2*m,vl(2*m,oo));
	FOR(i,0,2*m) FOR(j,0,2*m) {
		if ((b[i] & b[j]) == b[i]) adj[i][j] = 0;
	}
	FOR(i,0,m) adj[2*m-1-i][i] = -1;
	
	FOR(k,0,2*m) FOR(i,0,2*m) FOR(j,0,2*m) {
		if (adj[i][k] < oo && adj[k][j] < oo) {
			adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		}
	}
	
	bool res = true;
	FOR(i,0,m) if (adj[i][i] < 0) res = false;

	cout << (res ? "possible" : "impossible") << endl;
}