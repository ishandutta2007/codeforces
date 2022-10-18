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

	vl indeg(n);
	vvl adj(n), radj(n);

	while (m--) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		radj[b].pb(a);
		indeg[b]++;
	}

	queue<ll> q;
	FOR(i,0,n) if (!indeg[i]) q.push(i);

	vl v;
	while (sz(q)) {
		ll i = q.front();
		q.pop();
		v.pb(i);

		for (ll j: adj[i]) if (!--indeg[j]) q.push(j);
	}

	if (sz(v) < n) {
		cout << -1 << endl;
		return 0;
	}
	
	vl up(n), dn(n);
	iota(all(up),0);
	iota(all(dn),0);

	FOR(dir,0,2) {
		for (ll i: v) for (ll j: radj[i]) {
			dn[i] = min(dn[i], dn[j]);
		}
		swap(adj,radj);
		swap(up,dn);
		reverse(all(v));
	}

	ll cnt = 0;
	string res(n,'E');
	FOR(i,0,n) {
		if (up[i] == i && dn[i] == i) res[i] = 'A', cnt++;
	}
	
	cout << cnt << endl << res << endl;
}