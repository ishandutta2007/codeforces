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

const ll maxN = 500100;
ll parent[maxN], height[maxN], subtree_size[maxN];
ll on_edge[maxN], vertex_mask[maxN], big_child[maxN];
ll start_time[maxN], finish_time[maxN], dfs_order[maxN];
vl children[maxN];

ll T = 0;
void dfs_init(ll i, ll mask = 0) {
	dfs_order[T] = i;
	start_time[i] = T++;
	subtree_size[i] = 1;
	vertex_mask[i] = mask;
	big_child[i] = -1;
	for (ll j: children[i]) {
		height[j] = height[i]+1;
		dfs_init(j, mask ^ (1 << on_edge[j]));
		subtree_size[i] += subtree_size[j];
		if (big_child[i] == -1 || subtree_size[j] > subtree_size[big_child[i]])
			big_child[i] = j;
	}
	finish_time[i] = T;
}

const ll C = 22, M = 1 << C;
ll best[M], cur;
ll res[maxN];

void add(ll i) {
	best[vertex_mask[i]] = max(best[vertex_mask[i]], height[i]);
}

void relax(ll i, ll root) {
	FOR(k,0,C+1) {
		ll mask = (M-1) & (vertex_mask[i] ^ (1 << k));
		cur = max(cur, height[i] + best[mask] - 2*height[root]);
	}
}

ll dfs(ll i, bool clear = false) {
	for (ll j: children[i]) if (j != big_child[i]) {
		res[i] = max(res[i], dfs(j, true));
	}
	
	if (big_child[i] != -1)
		res[i] = max(res[i], dfs(big_child[i], false));
	
	for (ll j: children[i]) if (j != big_child[i]) {
		FOR(t,start_time[j],finish_time[j])
			relax(dfs_order[t],i);
		FOR(t,start_time[j],finish_time[j])
			add(dfs_order[t]);
	}
	relax(i,i);
	add(i);
	
	res[i] = max(res[i],cur);

	if (clear) {
		FOR(t,start_time[i],finish_time[i])
			best[vertex_mask[dfs_order[t]]] = -oo;
		cur = 0;
	}
	return res[i];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	FOR(i,1,n) {
		char c;
		cin >> parent[i] >> c;
		parent[i]--;
		on_edge[i] = c - 'a';
		children[parent[i]].pb(i);
	}
	
	dfs_init(0);
	
	FOR(i,0,M) best[i] = -oo;
	cur = 0;
	dfs(0);
	
	FOR(i,0,n) cout << res[i] << " \n"[i+1 == n];

}