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

bool ok = true;
vector<pll> adj[100100];
ll col[100100];

void dfs(ll i) {
	for (const auto &e: adj[i]) {
		ll j, c;
		tie(j,c) = e;
		if (col[j] == -1) {
			col[j] = col[i] ^ c ^ 1;
			dfs(j);
		} else {
			if (col[j] ^ col[i] ^ c ^ 1) ok = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m, n; cin >> m >> n;
	vl edge_col(m);
	FOR(i,0,m) cin >> edge_col[i];
	
	vvl edge_ends(m);

	FOR(i,0,n) {
		ll x; cin >> x;
		while (x--) {
			ll j; cin >> j;
			j--;
			edge_ends[j].pb(i);
		}
	}
	
	FOR(i,0,m) {
		ll a = edge_ends[i][0], b = edge_ends[i][1], c = edge_col[i];
		adj[a].eb(b,c);
		adj[b].eb(a,c);
	}
	
	memset(col,-1,sizeof col);
	FOR(i,0,n) if (col[i] == -1) {
		col[i] = 0;
		dfs(i);
	}
	cout << (ok ? "YES" : "NO") << endl;

}