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
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

typedef tuple<ll,ll,bool> edge;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, k; cin >> n >> m >> k;
	vector<vector<edge>> adj(n);
	while (m--) {
		ll a, b, c; cin >> a >> b >> c;
		a--, b--;
		adj[a].pb(edge{b,c,false}), adj[b].pb(edge{a,c,false});
	}
	FOR(i,0,k) {
		ll b, c; cin >> b >> c;
		b--;
		adj[0].pb(edge{b,c,true});
	}
	
	vl dist(n,oo);
	priority_queue<edge,vector<edge>,greater<edge>> q;
	
	q.push(edge{0,0,0});
	while (sz(q)) {
		ll i, d; bool is_rail;
		tie(d,i,is_rail) = q.top(); q.pop();
		
		if (d >= dist[i]) continue;
		
		dist[i] = d;
		if (is_rail) k--;

		for (const auto &e: adj[i]) {
			ll j, len;
			tie(j,len,is_rail) = e;
			q.push(edge{d+len,j,is_rail});
		}
	}
	cout << k << endl;
}