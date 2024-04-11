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
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })


ll r;
vl res;
vector<vector<pll>> adj;

void dfs(ll i, ll p, ll cp) {
	if (sz(adj[i]) > r) {
		ll cj = 0;
		for (auto e: adj[i]) {
			ll j = e.xx, k = e.yy;
			if (j == p) continue;
			res[k] = cj;
			dfs(j,i,cj);
		}
	} else {
		ll cj = 0;
		for (auto e: adj[i]) {
			ll j = e.xx, k = e.yy;
			if (j == p) continue;
			if (cj == cp) cj++;
			res[k] = cj;
			dfs(j,i,cj);
			cj++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k;
	cin >> n >> k;

	adj.resize(n);
	FOR(i,0,n-1) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].eb(b,i);
		adj[b].eb(a,i);
	}
	
	vl degs(n);
	FOR(i,0,n) degs[i] = sz(adj[i]);
	sort(all(degs),greater<ll>());
	
	r = degs[k];
	res.resize(n-1);
	
	dfs(0,-1,-1);
	
	cout << r << endl;
	FOR(i,0,n-1) cout << res[i]+1 << " ";
	cout << endl;

}