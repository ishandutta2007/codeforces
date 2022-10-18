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

ll k;
vvl adj;
vl col;

void dfs(ll i, ll p = 0) {
	ll c = 0;
	for (ll j: adj[i]) if (j != p) {
		while (col[i] == c || col[p] == c) c++;
		col[j] = c++;
		dfs(j,i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	
	adj.resize(n);

	FOR(i,1,n) {
		ll a, b; cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	k = 0;
	FOR(i,0,n) k = max(k,1 + sz(adj[i]));
	
	col.resize(n);
	col[0] = 0;
	dfs(0);
	
	cout << k << endl;
	FOR(i,0,n) cout << col[i]+1 << " \n"[i+1 == n];

}