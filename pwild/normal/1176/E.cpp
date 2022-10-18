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

void dfs(ll i, vl &col, vvl &adj) {
	for (ll j: adj[i]) if (col[j] == -1) {
		col[j] = 1-col[i];
		dfs(j,col,adj);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n, m;
		cin >> n >> m;
		vvl adj(n);
		while (m--) {
			ll a, b;
			cin >> a >> b;
			a--, b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		
		vl col(n,-1);
		col[0] = 0;
		dfs(0,col,adj);
		
		ll cnt = accumulate(all(col),0);
		if (cnt < n-cnt) {
			cout << cnt << '\n';
			FOR(i,0,n) if (col[i] == 1) cout << i+1 << " ";
			cout << '\n';
		} else {
			cout << n-cnt << '\n';
			FOR(i,0,n) if (col[i] == 0) cout << i+1 << " ";
			cout << '\n';
		}
	}
}