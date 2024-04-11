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

const ll K = 20, MOD = 998244353;

ll small(vvl adj) {
	ll n = sz(adj);
	
	vvl radj(n);
	FOR(i,0,n) for (ll j: adj[i]) radj[j].pb(i);

	vvl dist(n, vl(K,oo));
	set<tuple<ll,ll,ll>> q;
	
	dist[0][0] = 0, q.emplace(0,0,0);
	while (sz(q)) {
		auto [d,i,s] = *begin(q);
		q.erase(begin(q));

		vl &nei = s%2 == 0 ? adj[i] : radj[i];
		for (ll j: nei) {
			if (d+1 >= dist[j][s]) continue;
			q.erase({dist[j][s],j,s});
			dist[j][s] = d+1;
			q.emplace(d+1,j,s);
		}

		if (s+1 >= K || d + (1 << s) >= dist[i][s+1]) continue;
		q.erase({dist[i][s+1],i,s+1});
		dist[i][s+1] = d + (1 << s);
		q.emplace(d + (1 << s), i, s+1);
	}
	
	return *min_element(all(dist[n-1]));
}

ll big(vvl adj) {
	ll n = sz(adj);
	
	vvl radj(n);
	FOR(i,0,n) for (ll j: adj[i]) radj[j].pb(i);

	vector<vector<pll>> dist(n, vector<pll>(2, {oo,0}));
	set<tuple<ll,ll,ll,ll>> q;

	dist[0][0] = {0,0}, q.emplace(0,0,0,0);
	while (sz(q)) {
		auto [d,e,i,s] = *begin(q);
		q.erase(begin(q));

		vl &nei = s == 0 ? adj[i] : radj[i];
		for (ll j: nei) {
			if (mp(d,e+1) >= dist[j][s]) continue;
			q.erase({dist[j][s].xx,dist[j][s].yy,j,s});
			dist[j][s] = {d,e+1};
			q.emplace(d,e+1,j,s);
		}

		if (mp(d+1,e) >= dist[i][1-s]) continue;
		q.erase({dist[i][1-s].xx,dist[i][1-s].yy,i,1-s});
		dist[i][1-s] = {d+1,e};
		q.emplace(d+1,e,i,1-s);
	}

	auto [d,e] = *min_element(all(dist[n-1]));
	ll res = e, p = 1;
	while (d--) {
		res = (res + p) % MOD;
		p = 2*p % MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m;
	cin >> n >> m;

	vvl adj(n);
	while (m--) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
	}
	
	ll res = small(adj);
	if (res == oo) res = big(adj);
	cout << res << endl;
}