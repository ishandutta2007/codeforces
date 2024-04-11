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

bool is_bipartite(ll i, const vvl &adj, vl &col, vl &root, ll r = -1) {
	if (r != -1) root[i] = r;
	bool res = true;
	for (ll j: adj[i]) {
		if (col[j] == -1) {
			col[j] = 1-col[i];
			if (!is_bipartite(j, adj, col, root, r)) res = false;
		}
		if (col[j] == col[i]) res = false;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, k;
	cin >> n >> m >> k;

	vl team(n);
	FOR(i,0,n) cin >> team[i], team[i]--;
	
	vvl adj(n);
	map<pll,vector<pll>> edges;
	while (m--) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		if (team[a] == team[b]) {
			adj[a].pb(b);
			adj[b].pb(a);
		} else {
			ll s = team[a], t = team[b];
			if (s > t) swap(s,t);
			edges[{s,t}].eb(a,b);
		}
	}
	
	vl team_ok(k,1);
	vl col(n,-1), root(n,-1);
	FOR(i,0,n) if (col[i] == -1) {
		col[i] = 0;
		if (!is_bipartite(i, adj, col, root, i)) {
			team_ok[team[i]] = 0;
		}
	}

	ll cnt_ok = accumulate(all(team_ok),0LL);

	ll res = cnt_ok*(cnt_ok-1)/2;

	vvl nadj(2*n);
	FOR(i,0,n) {
		nadj[i].pb(n+i);
		nadj[n+i].pb(i);
	}
	
	vl ncol(2*n,-1), nroot;
	for (auto [pr,es]: edges) {
		auto [s,t] = pr;
		if (!team_ok[s] || !team_ok[t]) continue;

		vector<pll> nes;
		for (auto [a,b]: es) {
			assert(col[root[a]] == 0);
			assert(col[root[b]] == 0);
			nes.eb(col[a]*n + root[a], col[b]*n + root[b]);
		}
		
		for (auto [a,b]: nes) {
			nadj[a].pb(b);
			nadj[b].pb(a);
		}
		
		for (auto [a,b]: nes) if (ncol[a] == -1) {
			if (!is_bipartite(a, nadj, ncol, nroot, -1)) {
				res--;
				break;
			}
		}

		for (auto [a,b]: nes) {
			nadj[a].pop_back();
			nadj[b].pop_back();
			ncol[a] = ncol[(a+n)%(2*n)] = -1;
			ncol[b] = ncol[(b+n)%(2*n)] = -1;
		}
	}

	cout << res << endl;
}