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

const ll maxN = 100010, MOD = 1000000007;

bool ok = true;

ll col[maxN], comp[maxN];
vector<pll> adj[maxN];

void dfs(ll i) {
	for (const auto &e: adj[i]) {
		if (comp[e.xx] != -1) {
			if (col[e.xx] != (col[i] ^ e.yy)) ok = false;
		} else {
			comp[e.xx] = comp[i];
			col[e.xx] = col[i] ^ e.yy;
			dfs(e.xx);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m; cin >> n >> m;
	
	FOR(i,0,n) comp[i] = -1;

	FOR(i,0,m) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a].eb(b,!c);
		adj[b].eb(a,!c);
	}

	ll C = 0;
	FOR(i,0,n) if (comp[i] == -1) {
		comp[i] = C++;
		dfs(i);
	}

	if (!ok) {
		cout << 0 << endl;
		return 0;
	}
	
	ll res = 1;
	FOR(k,1,C) res = (2*res) % MOD;

	cout << res << endl;


}