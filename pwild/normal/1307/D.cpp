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
	queue<ll> q;
	vl dist(sz(adj),oo);
	dist[s] = 0, q.push(s);

	while (sz(q)) {
		ll i = q.front(); q.pop();
		for (ll j: adj[i]) if (dist[j] == oo) {
			dist[j] = dist[i] + 1;
			q.push(j);
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, k;
	cin >> n >> m >> k;

	vl a(k);
	FOR(i,0,k) cin >> a[i], a[i]--;

	vvl adj(n);
	while (m--) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	vl da = bfs(adj,0);
	vl db = bfs(adj,n-1);
	
	vector<pll> p(k);
	FOR(i,0,k) p[i] = {da[a[i]], db[a[i]]};
	sort(all(p), [&](pll a, pll b) { return a.xx-a.yy < b.xx-b.yy; });
	
	ll res = -oo, ymax = -oo;
	FORD(i,0,k) {
		res = max(res, p[i].xx + ymax + 1);
		ymax = max(ymax, p[i].yy);
	}

	res = min(res, da[n-1]);
	cout << res << endl;
}