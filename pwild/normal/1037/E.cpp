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
	
	ll n, m, k;
	cin >> n >> m >> k;
	
	vector<pll> edges;
	vector<set<ll>> adj(n);

	FOR(i,0,m) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		edges.eb(a,b);
		adj[a].insert(b);
		adj[b].insert(a);
	}

	reverse(all(edges));
	vl res;
	
	ll remaining = n;
	vb deleted(n);
	queue<ll> Q;

	auto try_enqueue = [&](ll i) {
		if (sz(adj[i]) >= k) return;
		if (deleted[i]) return;
		Q.push(i);
		deleted[i] = true;
		remaining--;
	};

	FOR(i,0,n) if (sz(adj[i]) < k) try_enqueue(i);

	for (pll e: edges) {
		while (!Q.empty()) {
			ll i = Q.front();
			Q.pop();
			for (ll j: adj[i]) {
				adj[j].erase(i);
				try_enqueue(j);
			}
		}
		
		res.pb(remaining);

		ll a, b;
		tie(a,b) = e;
		adj[a].erase(b);
		adj[b].erase(a);
		try_enqueue(a);
		try_enqueue(b);
	}

	reverse(all(res));
	for (ll x: res) cout << x << "\n";
}