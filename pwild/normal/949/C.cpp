#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
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

struct scc {
	ll n, C = 0, T = 0, top = -1;
	vl comp, t, st;
	vvl adj;

	ll dfs(ll i) {
		ll tmin = t[i] = T++;
		st[++top] = i;
		for (ll j: adj[i]) if (comp[j] == -1) {
			tmin = min(tmin, t[j] == -1 ? dfs(j) : t[j]);
		}
		if (tmin == t[i]) {
			while (st[top] != i) comp[st[top--]] = C;
			comp[st[top--]] = C++;
		}
		return tmin;
	}

	scc(vvl adj): n(sz(adj)), comp(n,-1), t(n,-1), st(n), adj(adj) {
		FOR(i,0,n) if (t[i] == -1) dfs(i);
	}

	vl find_smallest_bottom() {
		vb is_bot(C,true);
		FOR(i,0,n) for (ll j: adj[i]) {
			if (comp[i] != comp[j]) is_bot[comp[i]] = false;
		}
		
		vl size(C);
		FOR(i,0,n) size[comp[i]]++;
		
		ll d = -1;
		FOR(c,0,C) if (is_bot[c]) {
			if (d == -1 || size[c] < size[d]) d = c;
		}
		
		vl res;
		FOR(i,0,n) if (comp[i] == d) res.pb(i);
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, h;
	cin >> n >> m >> h;
	
	vl u(n);
	FOR(i,0,n) cin >> u[i];

	vvl adj(n);
	FOR(i,0,m) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		
		FOR(dir,0,2) {
			if ((u[a]+1)%h == u[b]) adj[a].pb(b);
			swap(a,b);
		}
	}
	
	scc S(adj);
	vl res = S.find_smallest_bottom();
	cout << sz(res) << endl;
	for (ll x: res) cout << x+1 << " ";
	cout << endl;
}