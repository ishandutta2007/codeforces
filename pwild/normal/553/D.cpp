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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, k; cin >> n >> m >> k;

	vl f(k);
	FOR(i,0,k) {
		cin >> f[i];
		f[i]--;
	}
	vvl adj(n);
	FOR(i,0,m) {
		ll a, b; cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	double rmin = 0, rmax = 1;
	vl lastres;
	FOR(it,0,50) {
		double r = (rmin+rmax)/2;
		vl bad(n);
		vb mark(n);
		queue<ll> q;
		for (const ll &i: f) {
			q.push(i);
			mark[i] = true;
		}
		while (sz(q)) {
			ll i = q.front(); q.pop();
			for (const ll &j: adj[i]) {
				bad[j]++;
				if (double(sz(adj[j])-bad[j])/sz(adj[j]) < r && !mark[j]) {
					q.push(j);
					mark[j] = true;
				}
			}
		}
		vl res;
		FOR(i,0,n) if (!mark[i]) res.pb(i);
		if (sz(res)) {
			lastres = res;
			rmin = r;
		} else {
			rmax = r;
		}
	}
	//cerr << rmin << endl;
	if (!sz(lastres)) {
		vb mark(n);
		for (const ll &i: f) mark[i] = true;
		FOR(i,0,n) if (!mark[i]) lastres.pb(i);
	}
	cout << sz(lastres) << endl;
	FOR(i,0,sz(lastres)-1) cout << lastres[i]+1 << " ";
	cout << lastres[sz(lastres)-1]+1 << endl;
}