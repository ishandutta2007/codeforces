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

ll n, S, T;
ll cap[105][105];
bool mark[105];
vvl adj;
vl a;
vector<pll> b;

bool dfs(ll i) {
	if (i == T) return true;
	if (mark[i]) return false;
	mark[i] = true;
	for (const ll &j: adj[i]) if (cap[i][j] && dfs(j)) {
		cap[i][j]--, cap[j][i]++;
		return true;
	}
	return false;
}

ll flow() {
	ll res = 0;
	memset(mark,0,sizeof(mark));
	while (dfs(S)) res++, memset(mark,0,sizeof(mark));
	return res;
}

void add_edge(ll a, ll b, ll c) {
	adj[a].pb(b), adj[b].pb(a);
	cap[a][b] += c;
}

ll per_prime(ll p) {
	bool go = false;
	vl cnt(n);
	FOR(i,0,n) while (a[i] % p == 0) a[i] /= p, cnt[i]++, go = true;
	if (!go) return 0;

	FOR(i,0,n+2) adj[i].clear();
	memset(cap,0,sizeof(cap));
	FOR(i,0,n) if (i % 2) add_edge(i,T,cnt[i]); else add_edge(S,i,cnt[i]);
	for (const pll &e: b) {
		add_edge(e.xx,e.yy,oo);
	}
	return flow();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m; cin >> n >> m;
	
	a.resize(n);
	FOR(i,0,n) cin >> a[i];
	adj.resize(n+2);

	FOR(i,0,m) {
		ll x, y; cin >> x >> y;
		x--, y--;
		if (x % 2) swap(x,y);
		b.eb(x,y);
	}
	S = n, T = n+1;

	vb pr(1e5,true);
	FOR(i,2,1e5) if (pr[i]) for (ll j = i*i; j < 1e5; j += i) pr[j] = false;
	
	ll res = 0;
	FOR(i,2,1e5) if (pr[i]) {
		ll cur = per_prime(i);
		res += cur;
		//if (cur) cerr << i << " " << res << endl;
	}
	FOR(i,0,n) if (a[i] > 1) res += per_prime(a[i]);
	cout << res << endl;

}