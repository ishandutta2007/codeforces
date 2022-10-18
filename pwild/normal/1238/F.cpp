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

ll res = 0;
vvl adj;

ll dfs(ll i, ll p) {
	ll m1 = 0, m2 = 0, ch = 0;
	for (ll j: adj[i]) if (j != p) {
		ll c = dfs(j,i);
		if (c > m1) m2 = m1, m1 = c;
		else if (c > m2) m2 = c;
		ch++;
	}
	ll x = 1 + m1 + m2 + max(sz(adj[i])-2,0LL);
	ll y = 1 + m1 + max(ch-1,0LL);
	res = max(res,x);
//	TR(i), TR(x), TR(y);
//	cerr << endl;
	return y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		adj.assign(n,{});
		FOR(i,1,n) {
			ll a, b;
			cin >> a >> b;
			a--, b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		res = 0;
		dfs(0,-1);
		cout << res << endl;
	}
}