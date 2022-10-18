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

void solve() {
	ll n; cin >> n;
	n *= 2;

	vector<vector<pll>> adj(n);
	FOR(i,1,n) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a].eb(b,c);
		adj[b].eb(a,c);
	}
	
	vl size(n,1);
	function<void(ll,ll)> dfs = [&](ll i, ll p) {
		for (auto [j,len]: adj[i]) if (j != p) {
			dfs(j,i), size[i] += size[j], len = len;
		}
	};
	dfs(0,-1);
	
	ll rmin = 0, rmax = 0;
	FOR(i,0,n) for (auto [j,len]: adj[i]) if (size[j] < size[i]) {
		rmin += (size[j]%2) * len;
		rmax += min(size[j],n-size[j]) * len; 
	}
	cout << rmin << " " << rmax << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}