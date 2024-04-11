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

struct flow_network {
	struct edge { ll to, cap; };
	
	ll n, s, t;
	vb mark;
	vl ptr, dist;
	vvl adj;
	vector<edge> e;

	flow_network(ll n, ll s, ll t): n(n), s(s), t(t), adj(n) { }

	void add_edge(ll a, ll b, ll c) {
		adj[a].pb(sz(e));
		e.pb({b,c});
		adj[b].pb(sz(e));
		e.pb({a,0});
	}
	
	bool bfs() {
		dist.assign(n,oo);
		queue<ll> q;
		dist[s] = 0, q.push(s);
		while (sz(q)) {
			ll i = q.front(); q.pop();
			for (ll j: adj[i]) if (e[j].cap) {
				if (dist[e[j].to] < oo) continue;
				dist[e[j].to] = dist[i]+1, q.push(e[j].to);
			}
		}
		return dist[t] < oo;
	}

	ll dfs(ll i, ll cap) {
		if (!cap || i == t) return cap;
		for (; ptr[i] < sz(adj[i]); ptr[i]++) {
			ll j = adj[i][ptr[i]];
			if (dist[e[j].to] != dist[i]+1) continue;
			if (ll c = dfs(e[j].to, min(cap,e[j].cap))) {
				e[j].cap -= c, e[j^1].cap += c;
				return c;
			}
		}
		return 0;
	}

	ll max_flow() {
		ll flow = 0;
		while (bfs()) {
			ptr.assign(n,0);
			while (ll c = dfs(s,oo)) flow += c;
		}
		return flow;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m;
	cin >> n >> m;

	vl need(n);
	FOR(i,0,n) cin >> need[i];
	ll sum_need = accumulate(all(need),0LL);
	
	ll K = 4e5 + 10;
	vvl offers(K);
	while (m--) {
		ll d, i;
		cin >> d >> i;
		offers[d-1].pb(i-1);
	}
	
	ll tmin = sum_need-1, tmax = 2*sum_need;
	while (tmax-tmin > 1) {
		ll t = (tmin+tmax)/2;
		
		ll N = t + n + 2, src = N-2, dst = N-1;
		flow_network F(N,src,dst);
		FOR(d,0,t) {
			F.add_edge(src,d,1);
			if (d+1 < t) F.add_edge(d,d+1,oo);
			for (ll i: offers[d]) F.add_edge(d,t+i,oo);
		}
		FOR(i,0,n) F.add_edge(t+i,dst,need[i]);
		
		ll flow = F.max_flow();
		//TR(t), TR(flow);

		if (flow >= 2*sum_need-t) tmax = t;
		else tmin = t;
	}
	cout << tmax << endl;
}