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

ll C = 1;
vl d, comp;
stack<ll> st;
vvl adj;
vector<pll> bridges;
set<pll> res;

ll dfs(ll i, ll p, ll di, bool ins = false) {
	ll dmin = d[i] = di;
	st.push(i);
	for (const ll &j : adj[i]) if (j != p) {
		if (ins) {
			if (!has(res,pll(i,j))) res.insert(pll(j,i));
		}
		if (d[j] != -1) {
			dmin = min(dmin, d[j]);
		} else {
			ll dj = dfs(j,i,di+1,ins);
			if (dj > di) {
				bridges.eb(i,j);
				while (st.top() != j) comp[st.top()] = C, st.pop();
				comp[st.top()] = C++, st.pop();
			}
			dmin = min(dmin, dj);
		}
	}
	return dmin;
}

vb vis;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;
	adj.resize(n), d.resize(n,-1), comp.resize(n,0);
	
	vector<pll> edges(m);
	FOR(i,0,m) {
		ll a, b; cin >> a >> b;
		a--, b--;
		edges[i] = {a,b};
		adj[a].pb(b), adj[b].pb(a);
	}
	dfs(0,-1,0);
	assert(sz(bridges) == C-1);
	
	vl cnt(C);
	FOR(i,0,n) cnt[comp[i]]++;
	ll c = 0;
	FOR(i,1,C) if (cnt[i] > cnt[c]) c = i;
	
	d.assign(n,-1);
	FOR(i,0,n) if (comp[i] == c) {
		cerr << i << endl;
		dfs(i,-1,0,true);
		break;
	}
	cerr << sz(res) << endl;
	cout << cnt[c] << "\n";
	for (const auto &e: edges) {
		if (has(res,e)) cout << e.xx+1 << " " << e.yy+1 << "\n";
		else cout << e.yy+1 << " " << e.xx+1 << "\n";
	}

}