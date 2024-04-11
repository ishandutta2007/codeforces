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
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	vl col(n,-1), comp(n);
	ll C = 0;
	queue<ll> q;
	FOR(i,0,n) if (col[i] == -1) {
		q.push(i);
		col[i] = 0;
		while (sz(q)) {
			ll j = q.front(); q.pop();
			comp[j] = C;
			for (const ll &k: adj[j]) {
				if (col[k] == -1) {
					col[k] = !col[j];
					q.push(k);
				} else if (col[k] == col[j]) {
					cout << "0 1" << endl;
					return 0;
				}
			}
		}
		C++;
	}
	
	bool special = true;
	FOR(i,0,n) if (sz(adj[i]) >= 2) special = false;

	if (special) {
		if (m == 0) {
			cout << "3 " << n*(n-1)*(n-2)/6 << endl;
		} else {
			cout << "2 " << m*(n-2) << endl;
		}
	} else {
		cout << "1 ";
		ll res = 0;
		vvl cnt(C,vl(2));
		FOR(i,0,n) cnt[comp[i]][col[i]]++;
		FOR(i,0,C) FOR(j,0,2) res += cnt[i][j]*(cnt[i][j]-1)/2;
		cout << res << endl;
	}

}