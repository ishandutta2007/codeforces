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
vl sub_size, height;

ll dfs_size(ll i) {
	sub_size[i] = 1;
	FOR(k,0,26) if (adj[i][k] != -1) {
		height[adj[i][k]] = height[i] + 1;
		sub_size[i] += dfs_size(adj[i][k]);
	}
	return sub_size[i];
}

vector<pll> merges;
ll merge(ll i1, ll i2) {
	ll res = 1;
	FOR(k,0,26) if (adj[i2][k] != -1) {
		if (adj[i1][k] != -1) {
			res += merge(adj[i1][k], adj[i2][k]);
		} else {
			merges.eb(i1,k);
			adj[i1][k] = adj[i2][k];
		}
	}
	return res;
}

vl savings;

void dfs(ll i) {
	ll children = 0;
	ll heavy_child = -1;
	FOR(k,0,26) if (adj[i][k] != -1) {
		if (heavy_child == -1 || sub_size[adj[i][k]] > sub_size[heavy_child])
			heavy_child = adj[i][k];
		dfs(adj[i][k]);
		children++;
	}
	if (!children) return;

	savings[height[i]]++;
	merges.clear();
	FOR(k,0,26) if (adj[i][k] != -1 && adj[i][k] != heavy_child) {
		savings[height[i]] += merge(heavy_child, adj[i][k]);
	}
	for (const auto &p: merges) adj[p.xx][p.yy] = -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	adj.resize(n,vl(26,-1));
	FOR(i,1,n) {
		ll a, b; char c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a][c-'a'] = b;
	}
	
	sub_size.resize(n), height.resize(n);
	height[0] = 0;
	dfs_size(0);

	savings.resize(n);
	dfs(0);
	
	ll best_h = 0;
	FOR(h,1,n) if (savings[h] > savings[best_h]) best_h = h;
	cout << n-savings[best_h] << endl << best_h+1 << endl;

}