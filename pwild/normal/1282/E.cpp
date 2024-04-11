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
	vvl adj(n-2);
	map<pll,ll> M;

	FOR(i,0,n-2) {
		vl a(3);
		FOR(j,0,3) cin >> a[j], a[j]--;

		for (ll x: a) for (ll y: a) if (x < y) {
			pll p(x,y);
			if (M.count(p)) {
				ll j = M[p];
				M.erase(p);
				adj[i].pb(j);
				adj[j].pb(i);
			} else {
				M[p] = i;
			}
		}
	}

	vvl nei(n);
	assert(sz(M) == n);
	for (auto [p,i]: M) { i = i;
		auto [x,y] = p;
		nei[x].pb(y);
		nei[y].pb(x);
	}

	ll i = 0, j = nei[0][0];
	FOR(k,0,n) {
		cout << i+1 << " ";
		i ^= nei[j][0] ^ nei[j][1];
		swap(i,j);
	}
	cout << endl;

	vl deg(n-2);
	queue<ll> q;
	FOR(i,0,n-2) {
		deg[i] = sz(adj[i]);
		if (deg[i] == 1) q.push(i);
	}

	while (sz(q)) {
		ll i = q.front();
		q.pop();
		cout << i+1 << " ";
		for (ll j: adj[i]) if (--deg[j] == 1) q.push(j);
	}
	if (n == 3) cout << 1;
	cout << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		solve();
	}
}