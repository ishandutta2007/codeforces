#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
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

const ll K = 10;

struct tree {
	ll n, m;
	vl dep, leaves;
	vvl par;

	tree(ll m): m(m) {
		cin >> n;
		par.resize(n+1,vl(K));
		dep.resize(n+1);
		FOR(i,2,n+1) cin >> par[i][0];
		FOR(k,1,K) FOR(i,1,n+1) {
			par[i][k] = par[ par[i][k-1] ][k-1];
		}
		FOR(t,0,n+3) FOR(i,1,n+1) {
			dep[i] = dep[par[i][0]] + 1;
		}
		leaves.resize(m);
		FOR(i,0,m) cin >> leaves[i];
	}
	
	ll lca(ll a, ll b) {
		if (dep[a] < dep[b]) swap(a,b);
		ll dh = dep[a]-dep[b];
		FOR(k,0,K) if (dh & (1 << k)) a = par[a][k];
		if (a == b) return a;
		FORD(k,0,K) if (par[a][k] != par[b][k]) {
			a = par[a][k], b = par[b][k];
		}
		return par[a][0];
	}

	ll cost(ll i, ll j) {
		ll a = i ? leaves[i-1] : 1;
		ll b = j ? leaves[j-1] : 1;
		return dep[b]-dep[lca(a,b)];
	}
};

void self_min(ll &a, ll b) {
	a = min(a,b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m; cin >> m;
	tree A(m), B(m);

/*
	FOR(i,0,m) FOR(j,i+1,m+1) {
		cerr << i << " " << j << " " << B.cost(i,j) << endl;
	}
	return 0;
*/

	vvl dp(m+1,vl(m+1,1e9));
	dp[0][0] = 0;
	FOR(i,0,m) FOR(j,0,m) {
		ll k = max(i,j)+1;
		self_min(dp[k][j], dp[i][j] + A.cost(i,k));
		self_min(dp[i][k], dp[i][j] + B.cost(j,k));
	}
	
	ll res = 1e9;
	FOR(i,0,m) self_min(res, dp[i][m]);
	FOR(i,0,m) self_min(res, dp[m][i]);
	res = A.n + B.n - 2 - res;
	cout << res << endl;

}