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
	
	ll n, m;
	cin >> n >> m;
	
	ll C = 1;
	vvl v(n);
	FOR(i,0,n) {
		ll k; cin >> k;
		v[i].resize(k);
		FOR(j,0,k) cin >> v[i][j], v[i][j]--;
		C = max(C,k);
	}
	
	vvl adj(n);
	FOR(i,1,n) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	vl res(m,oo);
	
	function<void(ll,ll)> dfs = [&](ll i, ll p) {
		ll k = sz(v[i]);
		vb ok(k,true);
		for (ll x: v[i]) if (res[x] < k) ok[res[x]] = false;
		ll j = 0;
		for (ll x: v[i]) if (res[x] == oo) {
			while (!ok[j]) j++;
			res[x] = j;
			ok[j] = false;
		}
		for (ll j: adj[i]) if (j != p) dfs(j,i);
	};
	dfs(0,-1);
	
	cout << C << endl;
	FOR(i,0,m) if (res[i] == oo) res[i] = 0;
	FOR(i,0,m) cout << res[i]+1 << " \n"[i+1==m];

}