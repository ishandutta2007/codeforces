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
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

const ll N = 300100, K = 20;
ll sw[N], h[N], p[N][K], dp[N][K][2][2];
vl adj[N];

void dfs(ll i) {
	for (ll j: adj[i]) if (j != p[i][0]) {
		p[j][0] = i;
		h[j] = h[i]+1;
		dfs(j);
	}
}

ll lca(ll a, ll b) {
	if (h[a] < h[b]) swap(a,b);
	ll dh = h[a]-h[b];
	FOR(m,0,K) if (dh & (1 << m)) a = p[a][m];

	if (a == b) return a;

	FORD(m,0,K) {
		if (p[a][m] != p[b][m]) a = p[a][m], b = p[b][m];
	}
	return p[a][0];
}

vvl cost(ll a, ll b) {
	ll dh = h[a]-h[b];
	vvl res(2,vl(2));
	FOR(k1,0,2) FOR(k2,0,2) res[k1][k2] = (k1 != k2) * sw[a];
	FOR(m,0,K) if (dh & (1 << m)) {
		
		vvl nres(2,vl(2,oo));
		FOR(k1,0,2) FOR(k2,0,2) FOR(k3,0,2) {
			nres[k1][k3] = min(nres[k1][k3], res[k1][k2] + dp[a][m][k2][k3]);
		}

		a = p[a][m];
		res = nres;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	
	FOR(i,1,n+1) cin >> sw[i];
	
	vl a(n-1), b(n-1);
	vvl len(n-1,vl(2));
	FOR(i,0,n-1) {
		cin >> a[i] >> b[i] >> len[i][0] >> len[i][1];
	}
	
	FOR(i,0,n-1) adj[a[i]].pb(b[i]);
	FOR(i,0,n-1) adj[b[i]].pb(a[i]);
	
	vvl edges(n+1);
	FOR(i,0,n-1) edges[a[i]].pb(i);
	FOR(i,0,n-1) edges[b[i]].pb(i);

	{
		set<pll> q;
		FOR(i,1,n+1) q.emplace(sw[i],i);

		while (sz(q)) {
			ll i = begin(q)->yy;
			q.erase(begin(q));
			
			for (ll k: edges[i]) {
				ll j = a[k]^b[k]^i;

				ll cur = sw[i] + len[k][0] + len[k][1];
				if (cur >= sw[j]) continue;

				q.erase({sw[j],j});
				sw[j] = cur;
				q.insert({sw[j],j});
			}
		}
	}

	dfs(1);
	
	memset(dp,0x3f,sizeof dp);
	FOR(i,0,n-1) {
		if (p[b[i]][0] == a[i]) swap(a[i],b[i]);
		assert(p[a[i]][0] == b[i]);
		
		auto &d = dp[a[i]][0];

		FOR(k1,0,2) FOR(k2,0,2) FOR(k3,0,2) {
			d[k1][k3] = min(d[k1][k3], (k1 != k2) * sw[a[i]] + len[i][k2] + (k2 != k3) * sw[b[i]]);
		}
	}
	
	FOR(m,0,K-1) FOR(u,1,n+1) {
		ll v = p[u][m];
		p[u][m+1] = p[v][m];

		FOR(k1,0,2) FOR(k2,0,2) FOR(k3,0,2) {
			dp[u][m+1][k1][k3] = min(dp[u][m+1][k1][k3], dp[u][m][k1][k2] + dp[v][m][k2][k3]);
		}
	}
	
	ll q; cin >> q;
	while (q--) {
		ll u, v;
		cin >> u >> v;
		
		ll k1 = (u+1)%2, k3 = (v+1)%2;
		u = (u+1)/2, v = (v+1)/2;

		ll w = lca(u,v);
		
		vvl cu = cost(u,w), cv = cost(v,w);
		
		ll res = oo;
		FOR(k2,0,2) res = min(res, cu[k1][k2] + cv[k3][k2]);
		cout << res << endl;
	}
}