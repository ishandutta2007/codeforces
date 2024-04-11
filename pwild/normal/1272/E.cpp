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
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	vl dist(n,oo);
	vvl adj(n);
	queue<ll> q;
	
	FOR(i,0,n) for (ll j: {i-a[i],i+a[i]}) {
		if (j < 0 || j >= n) continue;
		if ((a[j]-a[i]) % 2) {
			dist[i] = 1;
			q.push(i);
		} else {
			adj[j].pb(i);
		}
	}

	while (sz(q)) {
		ll i = q.front();
		q.pop();
		for (ll j: adj[i]) {
			if (dist[j] < oo) continue;
			dist[j] = dist[i]+1;
			q.push(j);
		}
	}
	
	FOR(i,0,n) {
		ll x = dist[i];
		if (x == oo) x = -1;
		cout << x << " \n"[i+1==n];
	}
}