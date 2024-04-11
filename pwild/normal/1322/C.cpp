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
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n, m;
		cin >> n >> m;

		vl a(n);
		FOR(i,0,n) cin >> a[i];

		vvl adj(n);
		while (m--) {
			ll a, b;
			cin >> a >> b;
			adj[b-1].pb(a-1);
		}
		FOR(i,0,n) sort(all(adj[i]));
		
		vl is(n);
		iota(all(is),0);
		sort(all(is), [&](ll i, ll j) {
			return adj[i] < adj[j];
		});
		
		ll res = 0;
		FOR(u,0,n) if (u == 0 || adj[is[u]] != adj[is[u-1]]) {
			if (!sz(adj[is[u]])) continue;
			ll cur = 0, v = u;
			while (v < n && adj[is[u]] == adj[is[v]]) {
				cur += a[is[v++]];
			}
			res = gcd(res,cur);
		}
		cout << res << '\n';
	}
}