#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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

struct edmonds_karp {
	struct edge { ll to, cap; };
	
	ll n, s, t;
	vb mark;
	vvl adj;
	vector<edge> e;

	edmonds_karp(ll n, ll s, ll t): n(n), s(s), t(t), adj(n) { }

	void add_edge(ll a, ll b, ll c) {
		adj[a].pb(sz(e));
		e.pb({b,c});
		adj[b].pb(sz(e));
		e.pb({a,0});
	}
	
	ll dfs(ll i, ll cap, ll delta) {
		if (i == t) return cap;
		if (mark[i]) return 0;
		mark[i] = true;
		for (ll j: adj[i]) if (e[j].cap >= delta) {
			if (ll c = dfs(e[j].to, min(cap,e[j].cap), delta)) {
				e[j].cap -= c, e[j^1].cap += c;
				return c;
			}
		}
		return 0;
	}

	ll max_flow() {
		ll flow = 0, delta = 1;
		while (delta) {
			mark = vb(n);
			ll c = dfs(s,oo,delta);
			if (c) flow += c; else delta /= 2;
		}
		return flow;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;
	vector<pll> edges(m);
	FOR(i,0,m) {
		ll a, b; cin >> a >> b;
		a--, b--;
		edges[i] = {a,b};
	}
	
	auto go = [&](ll r, bool print = false) {
		edmonds_karp ek(n+m+2,n+m,n+m+1);
		FOR(i,0,m) ek.add_edge(n+i,edges[i].xx,1);
		FOR(i,0,m) ek.add_edge(n+i,edges[i].yy,1);
		FOR(i,0,m) ek.add_edge(ek.s,n+i,1);
		FOR(i,0,n) ek.add_edge(i,ek.t,r);
		
		ll res = ek.max_flow();
		if (print) {
			FOR(i,0,m) {
				ll a = edges[i].xx, b = edges[i].yy;
				if (ek.e[ek.adj[n+i][0]].cap) swap(a,b);
				cout << a+1 << " " << b+1 << endl;
			}
		}
		return res == m;
	};

	ll rmin = -1, rmax = n;
	while (rmax-rmin > 1) {
		ll r = (rmin+rmax)/2;
		if (go(r)) rmax = r; else rmin = r;
	}
	cout << rmax << endl;
	go(rmax,true);
}