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

ll k;
vector<vector<pll>> adj;

// == k | < k
pll dfs(ll i, ll p) {
	vl adds;
	ll base = 0;
	for (auto [j,c]: adj[i]) {
		if (j == p) continue;
		pll cur = dfs(j,i);
		base += cur.xx;
		adds.pb(max(cur.yy + c - cur.xx, 0LL));
	}
	sort(all(adds),greater<ll>());

	ll y = base;
	FOR(j,0,min(sz(adds),k-1)) y += adds[j];

	ll x = y;
	if (k <= sz(adds)) x += adds[k-1];
	
//	TR(i), TR(x), TR(y);
//	cerr << endl;
	return {x,y};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n;
		cin >> n >> k;
		adj.clear();
		adj.resize(n);
		FOR(i,1,n) {
			ll a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			adj[a].eb(b,c);
			adj[b].eb(a,c);
		}
		
		ll res = dfs(0,-1).xx;
		// FOR(i,0,n) cout << i << " " << dfs(i,-1).xx << endl;

		cout << res << '\n';
	}
}