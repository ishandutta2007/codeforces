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

vl bfs(vvl adj, ll s) {
	ll n = sz(adj);
	vl dist(n,oo);
	dist[s] = 0;
	queue<ll> q;
	q.push(s);
	while (sz(q)) {
		ll i = q.front();
		q.pop();
		for (ll j: adj[i]) if (dist[j] == oo) {
			dist[j] = dist[i]+1, q.push(j);
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n, m, a, b, c;
		cin >> n >> m >> a >> b >> c;
		a--, b--, c--;

		vl p(m);
		FOR(i,0,m) cin >> p[i];
		sort(all(p));

		vvl adj(n);
		FOR(i,0,m) {
			ll u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		vl dista = bfs(adj,a);
		vl distb = bfs(adj,b);
		vl distc = bfs(adj,c);
		
		vl sum(m+1);
		FOR(i,0,m) sum[i+1] = sum[i] + p[i];
		
		ll res = oo;
		FOR(d,0,n) {
			ll i = distb[d];
			ll j = dista[d] + distb[d] + distc[d];
			if (j > m) continue;
			res = min(res, sum[i] + sum[j]);
		}
		cout << res << endl;
	}
}