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

vl a;
vvl adj;
vl comp;
ll C = 0;

void dfs(ll i) {
	comp[i] = C;
	for (ll j: adj[i]) if (comp[j] == -1) dfs(j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	a.resize(n), adj.resize(n);
	comp.resize(n,-1);
	FOR(i,0,n) cin >> a[i], a[i]--;
	FOR(i,0,n) adj[i].pb(a[i]), adj[a[i]].pb(i);
	FOR(i,0,n) if (comp[i] == -1) dfs(i), C++; 
	
	vl compsz(C), compnd(C), cycsz(C), cycnd(C);
	ll root = -1;
	FOR(i,0,n) compsz[comp[i]]++, compnd[comp[i]] = i;
	FOR(c,0,C) {
		ll i = compnd[c];
		FOR(k,0,compsz[c]) i = a[i];
		cycnd[c] = i;
		do i = a[i], cycsz[c]++; while (i != cycnd[c]);
		if (cycsz[c] == 1) root = cycnd[c];
	}
	ll res = root == -1 ? C : C-1;
	if (root == -1) root = cycnd[0];
	FOR(c,0,C) a[cycnd[c]] = root;

	cout << res << endl;
	FOR(i,0,n) cout << a[i]+1 << " \n"[i+1 == n];
}