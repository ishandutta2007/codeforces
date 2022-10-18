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


const ll N = 3e5 + 10;
ll p[N], res[N];
set<ll> s[N];

ll Find(ll a) {
	if (a == p[a]) return a;
	return p[a] = Find(p[a]);
}

void Union(ll a, ll b, ll h) {
	a = Find(a), b = Find(b);
	if (a == b) return;
	if (s[a].size() > s[b].size()) swap(a,b);
	
	for (ll i: s[a]) {
		if (s[b].count(i)) {
			res[i] = h;
			s[b].erase(i);
		} else {
			s[b].insert(i);
		}
	}
	p[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, k, t;
	cin >> n >> m >> k >> t;

	vector<vector<pll>> adj(n);
	FOR(i,0,m) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a].eb(b,c);
		adj[b].eb(a,c);
	}

	vl dist(n,oo), closest(n,-1);
	FOR(i,0,k) dist[i] = 0, closest[i] = i;
	
	set<pll> q;
	FOR(i,0,k) q.insert({0,i});

	while (sz(q)) {
		ll i = begin(q)->yy;
		q.erase(begin(q));
		for (const auto &e: adj[i]) {
			ll j, len;
			tie(j,len) = e;
			if (dist[j] <= dist[i]+len) continue;
			q.erase({dist[j],j});
			dist[j] = dist[i]+len;
			closest[j] = closest[i];
			q.insert({dist[j],j});
		}
	}

//	FOR(i,0,n) cout << dist[i] << " \n"[i+1==n];
	
	iota(p,p+n,0);

	FOR(i,0,t) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		s[a].insert(i);
		s[b].insert(i);
	}

	vector<tuple<ll,ll,ll>> edges;
	FOR(i,0,n) for (auto [j,c]: adj[i]) if (i < j) {
		ll cost;
		if (closest[i] != closest[j]) cost = dist[i] + dist[j] + c;
		else cost = 0;
		edges.pb({cost,i,j});
	}
	sort(all(edges));

	for (auto [c,i,j]: edges) {
//		cout << i << " " << j << " " << c << endl;
		Union(i,j,c);
	}
	
	FOR(i,0,t) cout << res[i] << '\n';
}