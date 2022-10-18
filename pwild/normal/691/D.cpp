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
	
	ll n, m; cin >> n >> m;
	vl p(n);
	FOR(i,0,n) cin >> p[i], p[i]--;
	vvl adj(n);
	FOR(i,0,m) {
		ll a, b; cin >> a >> b;
		a--, b--;
		adj[a].pb(b), adj[b].pb(a);
	}
	
	vb mark(n);
	FOR(i,0,n) if (!mark[i]) {
		vl v, w;
		queue<ll> q;
		mark[i] = true, v.pb(i), w.pb(p[i]), q.push(i);
		while (sz(q)) {
			ll a = q.front(); q.pop();
			for (ll b: adj[a]) if (!mark[b]) {
				mark[b] = true, v.pb(b), w.pb(p[b]), q.push(b);
			}
		}
		sort(all(v)), sort(all(w),greater<ll>());
		FOR(i,0,sz(v)) p[v[i]] = w[i];
	}
	FOR(i,0,n) cout << p[i]+1 << " \n"[i+1 == n];
}