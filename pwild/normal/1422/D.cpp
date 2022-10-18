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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll m;
	cin >> m >> m;

	ll sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	
	if (m == 0) {
		cout << abs(sx-tx) + abs(sy-ty) << endl;
		return 0;
	}

	ll n = 0;
	map<pll,ll> id;
	auto get_id = [&](ll x, ll k) {
		pll p(x,k);
		if (!id.count(p)) id[p] = n++;
		return id[p];		
	};

	vl x(m+1), y(m+1);
	FOR(i,0,m+1) {
		if (i < m) cin >> x[i] >> y[i];
		else x[i] = sx, y[i] = sy;
		get_id(x[i],0);
		get_id(y[i],1);
	}

	vl xs = x, ys = y;
	sort(all(xs)), sort(all(ys));
	xs.erase(unique(all(xs)),end(xs));
	ys.erase(unique(all(ys)),end(ys));
	
	vector<vector<pll>> adj(n);
	
	FOR(i,0,m+1) {
		cin >> x[i] >> y[i];
		ll u = get_id(x[i],0);
		ll v = get_id(y[i],1);
		adj[u].eb(v,0);
		adj[v].eb(u,0);
	}
	FOR(i,0,sz(xs)-1) {
		ll u = get_id(xs[i],0);
		ll v = get_id(xs[i+1],0);
		ll dx = xs[i+1]-xs[i];
		adj[u].eb(v,dx);
		adj[v].eb(u,dx);
	}
	FOR(i,0,sz(ys)-1) {
		ll u = get_id(ys[i],1);
		ll v = get_id(ys[i+1],1);
		ll dy = ys[i+1]-ys[i];
		adj[u].eb(v,dy);
		adj[v].eb(u,dy);
	}
	
	vl dist(n,oo);

	set<pll> q;
	dist[get_id(sx,0)] = 0;
	q.insert({0,get_id(sx,0)});

	while (sz(q)) {
		ll i = begin(q)->yy;
		q.erase(begin(q));
		for (const auto &e: adj[i]) {
			ll j, len;
			tie(j,len) = e;
			if (dist[j] <= dist[i]+len) continue;
			q.erase({dist[j],j});
			dist[j] = dist[i]+len;
			q.insert({dist[j],j});
		}
	}
	
	ll res = oo;
	FOR(i,0,m+1) {
		ll cur = dist[get_id(x[i],0)] + abs(x[i]-tx) + abs(y[i]-ty);
		res = min(res,cur);
	}
	cout << res << endl;
}