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

const ll N = 500500;
vl adj[N], res;

void rec(ll i, ll p) {
	for (ll j: adj[i]) if (j != p) res.pb(j);
	reverse(all(adj[i]));
	res.pb(~i);
	for (ll j: adj[i]) if (j != p) rec(j,i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;

	FOR(i,1,n) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	res.pb(0);
	rec(0,-1);
	
	vl from(n), to(n);
	FOR(i,0,2*n) {
		ll k = res[i];
		if (k >= 0) {
			from[k] = i+1;
		} else {
			to[~k] = i+1;
		}
	}

	FOR(i,0,n) cout << from[i] << " " << to[i] << endl;
}