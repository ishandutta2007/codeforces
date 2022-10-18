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

struct scc {
	ll n, C = 0, T = 0, top = -1;
	vl comp, t, st;
	vvl adj;
 
	ll dfs(ll i) {
		ll tmin = t[i] = T++;
		st[++top] = i;
		for (ll j: adj[i]) if (comp[j] == -1) {
			tmin = min(tmin, t[j] == -1 ? dfs(j) : t[j]);
		}
		if (tmin == t[i]) {
			while (st[top] != i) comp[st[top--]] = C;
			comp[st[top--]] = C++;
		}
		return tmin;
	}
 
	scc(vvl adj): n(sz(adj)), comp(n,-1), t(n,-1), st(n), adj(adj) {
		FOR(i,0,n) if (t[i] == -1) dfs(i);
	}
};
 
struct sat2 {
	ll n;
	vvl adj;
 	vl val;
 
	sat2(ll n): n(n), adj(2*n), val(n) { }
 
	void add(ll a, ll b) { adj[n+a].pb(n+b), adj[n+~b].pb(n+~a); }
 
	void Or   (ll a, ll b) { add(~a,b); }
	void True (ll a)       { Or(a,a); }
	void False(ll a)       { True(~a); }
	void Same (ll a, ll b) { add(a,b), add(b,a); }
	void Xor  (ll a, ll b) { Same(a,~b); }
 
	void AtMostOne(vl as) {
		for (ll a: as) for (ll b: as) if (a < b) Or(~a,~b);
	}
 
	bool check() {
		scc s(adj);
		FOR(i,0,n) if (s.comp[n+~i] == s.comp[n+i]) return false;
		FOR(i,0,n) val[i] = s.comp[n+~i] > s.comp[n+i];
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;

	sat2 s(m);
	vvl a(n);
	FOR(i,0,n) {
		ll k; cin >> k;
		a[i].resize(k);
		FOR(j,0,k) cin >> a[i][j], a[i][j]--;
	}
	
	bool ok = true;
	FOR(i,0,n-1) {
		ll j = 0;
		vl &b = a[i], &c = a[i+1];
		while (j < min(sz(b),sz(c)) && b[j] == c[j]) j++;
		if (j < min(sz(b),sz(c))) {
			if (b[j] > c[j]) s.True(b[j]), s.False(c[j]);
			else s.Or(b[j],~c[j]);
		} else if (sz(b) > sz(c)) ok = false;
	}
	if (!ok || !s.check()) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
		vl res;
		FOR(i,0,m) if (s.val[i]) res.pb(i);
		cout << sz(res) << endl;
		FOR(i,0,sz(res)) cout << res[i]+1 << " \n"[i+1==sz(res)];
	}
}