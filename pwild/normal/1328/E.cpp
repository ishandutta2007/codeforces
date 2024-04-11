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

const ll N = 200100, K = 20;
ll p[N][K], d[N];
vl adj[N];

void dfs(ll i) {
	FOR(k,1,K) p[i][k] = p[ p[i][k-1] ][k-1];

	for (ll j: adj[i]) if (j != p[i][0]) {
		d[j] = d[i]+1;
		p[j][0] = i;
		dfs(j);
	}
}

ll lca(ll a, ll b) {
	if (d[a] < d[b]) swap(a,b);
	ll dh = d[a]-d[b];
	FOR(k,0,K) if (dh & (1 << k)) a = p[a][k];

	if (a == b) return a;
	FORD(k,0,K) if (p[a][k] != p[b][k]) {
		a = p[a][k], b = p[b][k];
	}
	return p[a][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m;
	cin >> n >> m;
	
	FOR(i,1,n) {
		ll a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	dfs(1);
	
	while (m--) {
		ll k; cin >> k;
		vl a(k);
		FOR(i,0,k) cin >> a[i];
		sort(all(a), [&](ll i, ll j) { return d[i] > d[j]; });
		
		bool ok = true;
		FOR(i,1,k) {
			ll c = lca(a[0], a[i]);
			if (a[i] != c && p[a[i]][0] != c) ok = false;
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}