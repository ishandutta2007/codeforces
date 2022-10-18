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
	vvl adj(n);
	FOR(i,0,m) {
		ll a, b; cin >> a >> b;
		--a, --b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	ll s1, t1, l1, s2, t2, l2;
	cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
	--s1, --t1, --s2, --t2;

	vvl dist(n,vl(n,oo));
	FOR(i,0,n) {
		queue<ll> q;
		dist[i][i] = 0;
		q.push(i);
		while (sz(q)) {
			ll j = q.front(); q.pop();
			for (const ll &k: adj[j]) if (dist[i][k] == oo) {
				dist[i][k] = dist[i][j] + 1;
				q.push(k);
			}
		}
	}
	
	if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
		cout << -1 << endl;
		return 0;
	}

	ll res = dist[s1][t1]  + dist[s2][t2];
	FOR(j1,0,n) FOR(j2,0,n) {
		ll path1 = dist[s1][j1] + dist[j1][j2] + dist[j2][t1];
		ll path2 = dist[s2][j1] + dist[j1][j2] + dist[j2][t2];
		if (path1 <= l1 && path2 <= l2) res = min(res,path1+path2-dist[j1][j2]);
		path2 = dist[s2][j2] + dist[j1][j2] + dist[j1][t2];
		if (path1 <= l1 && path2 <= l2) res = min(res,path1+path2-dist[j1][j2]);
	}
	
	cout << m-res << endl;

}