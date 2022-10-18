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

void fail() {
	cout << "NO" << endl;
	exit(0);
}

void dfs(ll i, const vvl &adj, vl &col) {
	for (ll j: adj[i]) {
		if (col[j] == -1) {
			col[j] = 1-col[i];
			dfs(j,adj,col);
		}
		if (col[i] == col[j]) fail();
	}
}

struct info {
	ll lo = -oo, hi = oo;
};

info operator+(info a, info b) {
	return {a.lo+b.lo, a.hi+b.hi};
}

info operator^(info a, info b) {
	return {max(a.lo,b.lo), min(a.hi,b.hi)};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m;
	cin >> n >> m;

	vl a(m), b(m), c(m);
	FOR(i,0,m) cin >> a[i] >> b[i] >> c[i], a[i]--, b[i]--;

	{
		vvl adj(n);
		FOR(i,0,m) adj[a[i]].pb(b[i]);
		FOR(i,0,m) adj[b[i]].pb(a[i]);
		
		vl col(n,-1);
		col[0] = 0;
		dfs(0,adj,col);
	}
	
	vector<vector<info>> dist(n, vector<info>(n));
	FOR(i,0,n) dist[i][i] = {0,0};
	FOR(i,0,m) {
		if (c[i]) {
			dist[a[i]][b[i]] = {1,1};
			dist[b[i]][a[i]] = {-1,-1};
		} else {
			dist[a[i]][b[i]] = dist[b[i]][a[i]] = {-1,1};
		}
	}

	FOR(k,0,n) FOR(i,0,n) FOR(j,0,n) {
		dist[i][j] = dist[i][j] ^ (dist[i][k] + dist[k][j]);
	}

	FOR(i,0,n) if (dist[i][i].hi < dist[i][i].lo) fail();

	cout << "YES" << endl;
	
	ll res = 0;
	FOR(i,0,n) FOR(j,0,n) res = max(res, dist[i][j].hi);
	cout << res << endl;


	FOR(i,0,n) FOR(j,0,n) if (dist[i][j].hi == res) {
		FOR(k,0,n) cout << dist[i][k].hi << " \n"[k+1==n];
		return 0;
	}
}