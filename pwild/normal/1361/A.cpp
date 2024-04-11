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

	vvl adj(n);
	while (m--) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	vl col(n);
	FOR(i,0,n) {
		cin >> col[i];
		col[i]--;
	}

	vl mark(n);

	FOR(i,0,n) {
		for (ll j: adj[i]) mark[col[j]] = 1;

		FOR(k,0,col[i]) if (!mark[k]) {
			cout << -1 << endl;
			return 0;
		}
		if (mark[col[i]]) {
			cout << -1 << endl;
			return 0;
		}

		for (ll j: adj[i]) mark[col[j]] = 0;
	}
	
	vl res(n);
	iota(all(res),0);
	sort(all(res), [&](ll i, ll j) { return col[i] < col[j]; });
	
	for (ll x: res) cout << x+1 << " ";
	cout << endl;


}