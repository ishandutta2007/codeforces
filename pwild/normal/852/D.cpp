#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f;
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

const ll T = 1731311;

const ll maxL = 210, maxR = 610;
ll L, R;

vl adj[maxL];
ll matchL[maxL], matchR[maxR];
ll depth[maxL + 1];

bool bfs() {
	fill_n(depth, L + 1, oo);
	queue<int> q;
	FOR(i, 0, L) if (matchL[i] == R) {
		depth[i] = 0; q.push(i);
	}
	while (!q.empty()) {
		int i = q.front(); q.pop();
		if (depth[i] >= depth[L]) continue;
		for (const auto &j : adj[i]) {
			if (depth[matchR[j]] == oo) {
				depth[matchR[j]] = depth[i] + 1;
				q.push(matchR[j]);
			}
		}
	}
	return depth[L] < oo;
}

bool dfs(int i) {
	if (i == L) return true;
	for (const auto &j : adj[i]) {
		if (depth[matchR[j]] == depth[i] + 1 && dfs(matchR[j])) {
			matchL[i] = j; matchR[j] = i; return true;
		}
	}
	depth[i] = oo;
	return false;
}

int hopcroft_karp() {
	fill_n(matchL, L, R);
	fill_n(matchR, R, L);
	int matching = 0;
	while (bfs()) {
		FOR(i, 0, L) {
			if (matchL[i] == R && dfs(i)) matching++;
		}
	}
	return matching;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll v, e, n, k;
	cin >> v >> e >> n >> k;

	vvl dist(v,vl(v,oo));
	FOR(i,0,v) dist[i][i] = 0;
	vl s(n);
	FOR(i,0,n) cin >> s[i], s[i]--;
	while (e--) {
		ll a, b, c; cin >> a >> b >> c;
		a--, b--;
		dist[a][b] = dist[b][a] = min(dist[a][b],c);
	}
	
	FOR(k,0,v) FOR(i,0,v) FOR(j,0,v) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
	
	ll tmin = -1, tmax = T+1;
	while (tmax-tmin > 1) {
		ll t = (tmin+tmax) / 2;
		
		L = n, R = v;
		FOR(i,0,n) {
			adj[i].clear();
			FOR(j,0,v) if (dist[s[i]][j] <= t) adj[i].pb(j);
		}
		if (hopcroft_karp() >= k) tmax = t; else tmin = t;
	}
	if (tmax > T) tmax = -1;
	cout << tmax << endl;
}