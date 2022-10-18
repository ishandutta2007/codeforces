#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const long long oo = 0x3f3f3f3f3f3f3f3f;
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

const ll maxN = 2e5 + 10;

namespace dt {
	ll N;
	vl adj[maxN], rev[maxN];
	ll dom[maxN], semi[maxN], par[maxN], node[maxN], anc[maxN], label[maxN];
	stack<ll> bucket[maxN];

	void dfs(ll n, ll &cnt) {
		node[cnt] = n;
		semi[n] = cnt++;
		for (const auto &to : adj[n]) {
			if (semi[to] == -1) { par[to] = n; dfs(to, cnt); }
			rev[to].pb(n);
		}
	}

	void compress(ll n) {
		if (anc[anc[n]] != anc[n]) {
			compress(anc[n]);
			if (semi[label[anc[n]]] < semi[label[n]]) label[n] = label[anc[n]];
			anc[n] = anc[anc[n]];
		}
	}
	ll eval(ll n) {
		if (anc[n] == n) return n;
		compress(n);
		return label[n];
	}
	void dominator_tree(ll r) {
		FOR(i,0,N) dom[i] = semi[i] = -1;
		ll cnt = 0;
		dfs(r,cnt);
		FOR(i,0,N) anc[i] = label[i] = i;
		FORD(i,1,cnt) {
			ll n = node[i];
			FOR(i, 0, sz(rev[n])) semi[n] = min(semi[n], semi[eval(rev[n][i])]);
			bucket[node[semi[n]]].push(n);
			anc[n] = par[n];
			while (!bucket[par[n]].empty()) {
				ll m = bucket[par[n]].top();
				bucket[par[n]].pop();
				ll u = eval(m);
				dom[m] = (semi[u] < semi[m]) ? u : par[n];
			}
		}
		FOR(i,1,cnt) {
			ll n = node[i];
			if (dom[n] != node[semi[n]]) dom[n] = dom[dom[n]];
		}
		FOR(i,0,N) rev[i].clear();
	}

};

vl ch[maxN];
ll dfs(ll i) {
	ll res = 1;
	for (ll j: ch[i]) res += dfs(j);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	ll n, m, s; cin >> n >> m >> s;
	s--;
	
	vector<vector<pll>> adj(n);
	
	FOR(i,0,m) {
		ll u, v, w; cin >> u >> v >> w;
		u--, v--;
		adj[u].eb(v,w), adj[v].eb(u,w);
	}
	
	set<pair<long long,ll>> q;
	q.insert({0,s});
	vector<long long> dist(n,oo);
	dist[s] = 0;

	while (sz(q)) {
		ll i = begin(q)->yy;
		q.erase(begin(q));
		for (const auto &e: adj[i]) {
			int len, j;
			tie(j,len) = e;
			if (dist[j] <= dist[i] + len) continue;
			q.erase({dist[j],j});
			dist[j] = dist[i] + len;
			q.insert({dist[j],j});
		}
	}
	
	dt::N = n;
	FOR(i,0,n) for (const auto &e: adj[i]) {
		int len, j;
		tie(j,len) = e;
		if (dist[i] + len == dist[j]) dt::adj[i].pb(j);
	}
	dt::dominator_tree(s);
	
	FOR(i,0,n) if (dt::dom[i] != -1) ch[dt::dom[i]].pb(i);
	
	ll res = 0;
	for (ll i: ch[s]) res = max(res,dfs(i));
	cout << res << endl;

}