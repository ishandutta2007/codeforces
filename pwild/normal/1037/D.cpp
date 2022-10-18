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
	
	ll n; cin >> n;
	vvl adj(n);
	FOR(i,1,n) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	vl dist(n,oo), p(n);
	queue<ll> Q;
	Q.push(0);
	dist[0] = 0;

	while (sz(Q)) {
		ll i = Q.front();
		Q.pop();
		for (ll j: adj[i]) {
			if (dist[j] < oo) continue;
			dist[j] = dist[i]+1;
			p[j] = i;
			Q.push(j);
		}
	}
	
	vl a(n);
	FOR(i,0,n) cin >> a[i], a[i]--;
	
	vl ind(n);
	FOR(i,0,n) ind[a[i]] = i;
	
	bool ok = true;
	FOR(i,0,n-1) {
		if (dist[a[i]] > dist[a[i+1]]) ok = false;
	}
	FOR(i,1,n-1) {
		if (ind[p[a[i]]] > ind[p[a[i+1]]]) ok = false;
	}
	
	cout << (ok ? "Yes" : "No") << endl;
}