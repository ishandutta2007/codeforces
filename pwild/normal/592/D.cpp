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

vvl adj;
vb mark;

bool dfs(ll i, ll p) {
	for (ll j: adj[i]) if (j != p) mark[i] = dfs(j,i) || mark[i];
	return mark[i];
}

typedef tuple<ll,ll,ll> tl;

tl res(0,-1,-1);

pll dfs2(ll i, ll p) {
	vector<pll> ch;
	for (ll j: adj[i]) if (j != p && mark[j]) ch.pb(dfs2(j,i));
	if (!sz(ch)) return {-1,i};
	ch.pb({0,i});
	sort(all(ch));
	ll a = ch[0].yy, b = ch[1].yy;
	if (a > b) swap(a,b);
	tl cur(ch[0].xx+ch[1].xx,a,b);
	res = min(res,cur);
	return {-1+ch[0].xx,ch[0].yy};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	ll n, m;
	cin >> n >> m;
	
	adj.resize(n);
	mark.resize(n,false);
	FOR(i,1,n) {
		ll u, v; cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	FOR(i,0,m) {
		ll u; cin >> u;
		mark[u-1] = true;
	}
	FOR(i,0,n) if (mark[i]) {
		dfs(i,-1);
		break;
	}
	
	ll marked = 0;
	FOR(i,0,n) marked += mark[i];
	
	if (marked == 1) {
		FOR(i,0,n) if (mark[i]) {
			cout << i+1 << endl << 0 << endl;
		}
		return 0;
	}

    
	FOR(i,0,n) if (mark[i]) {
		dfs2(i,-1);
		break;
	}
	
	ll lp = get<0>(res), a = get<1>(res);
	
	cout << a+1 << endl;
	cout << 2*(marked-1) + lp << endl;


}