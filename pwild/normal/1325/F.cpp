#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f;
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
	
	ll k = 1;
	while (k*k < n) k++;

	vl indep;
	vl mark(n);
	while (sz(indep) < k) {
		vl deg(n);
		FOR(i,0,n) if (!mark[i]) {
			for (ll j: adj[i]) deg[i] += !mark[j];
		}

		ll bi = -1;
		FOR(i,0,n) if (!mark[i]) {
			if (bi == -1 || deg[i] < deg[bi]) bi = i;
		}
		
		if (deg[bi] >= k-1) {
			vl depth(n,oo);
			depth[bi] = 0;

			for (ll i = bi; ;) {
				ll ni = -1;
				for (ll j: adj[i]) {
					if (mark[j]) continue;
					if (depth[j] < oo) continue;
					ni = j;
				}

				if (ni != -1) {
					depth[ni] = depth[i]+1;
					i = ni;
					continue;
				}
				
				ll dmax = depth[i];
				ll dmin = dmax;
				for (ll j: adj[i]) dmin = min(dmin, depth[j]);
				
				vl cyc(dmax-dmin+1);
				FOR(j,0,n) if (depth[j] >= dmin && depth[j] <= dmax) {
					cyc[depth[j]-dmin] = j;
				}
				cout << 2 << endl;
				cout << sz(cyc) << endl;
				for (ll x: cyc) cout << x+1 << " ";
				cout << endl;
				return 0;
			}
		} else {
			indep.pb(bi);
			mark[bi] = true;
			for (ll i: adj[bi]) mark[i] = true;
		}
	}
	
	cout << "1" << endl;
	for (ll i: indep) cout << i+1 << " ";
	cout << endl;
}