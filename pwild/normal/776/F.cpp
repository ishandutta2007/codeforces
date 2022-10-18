#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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

struct cd {
	ll n;
	vvl adj;
	vl subtree_size;
	vvl children;
	vl mark;

	void dfs0(ll i, ll depth) {
		mark[i] = subtree_size[i] = 0;
		for (ll j: adj[i]) if (mark[j] == 1) dfs0(j,depth);
	}

	ll dfs1(ll i) {
		mark[i] = subtree_size[i] = 1;
		for (ll j: adj[i]) if (mark[j] == 0) {
			subtree_size[i] += dfs1(j);
		}
		return subtree_size[i];
	}

	ll find_centroid(ll i, ll cnt, ll p = -1) {
		bool is_centroid = cnt - subtree_size[i] <= cnt/2;
		ll j_heavy = -1;
		for (ll j: adj[i]) if (j != p && mark[j] == 1) {
			if (subtree_size[j] > cnt/2) is_centroid = false;
			if (j_heavy == -1 || subtree_size[j] > subtree_size[j_heavy])
				j_heavy = j;
		}
		if (is_centroid) return i;
		return find_centroid(j_heavy,cnt,i);
	}

	ll decompose_tree(ll i, ll depth = 0) {
		if (depth) dfs0(i,depth-1);
		ll cnt = dfs1(i);
		i = find_centroid(i,cnt);
		mark[i] = 2;
		for (ll j: adj[i]) if (mark[j] != 2) {
			children[i].pb(decompose_tree(j,depth+1));
		}
		return i;
	}

	vl centroid_decomp(vvl aadj) {
		adj = aadj;
		n = sz(adj);
		subtree_size.resize(n);
		mark.resize(n);
		children.resize(n);
		
		ll rt = decompose_tree(0);
		
		vl col(n);
		queue<ll> q;

		col[rt] = 1;
		q.push(rt);
		
		while (sz(q)) {
			ll i = q.front();
			q.pop();
			for (ll j: children[i]) {
				col[j] = col[i]+1;
				q.push(j);
			}
		}
		return col;
	}
} foo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;
	
	vvl adj(n);
	FOR(i,0,n) adj[i].pb((i+1)%n);
	FOR(i,0,n) adj[i].pb((i+n-1)%n);
	
	map<pll,ll> edge_id;

	FOR(i,0,m) {
		ll a, b; cin >> a >> b;
		a--, b--;
		edge_id[mp(a,b)] = i;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	FOR(i,0,n) sort(all(adj[i]));

	set<pll> done;
	vector<pair<vl,vl>> faces;

	FOR(i,0,n) for (const ll &j: adj[i]) {
		if (has(done,mp(i,j))) continue;
		if (j == (i+1)%n) continue;

		vl cur = {i,j};
		vl ids;
		ll a = i, b = j;
		done.emplace(i,j);
		if (has(edge_id,mp(i,j))) ids.pb(edge_id[mp(i,j)]);
		if (has(edge_id,mp(j,i))) ids.pb(edge_id[mp(j,i)]);
		while (true) {
			auto it = lower_bound(all(adj[b]),a);
			it++;
			if (it == end(adj[b])) it = begin(adj[b]);
			ll c = *it;
			done.emplace(b,c);
			if (has(edge_id,mp(b,c))) ids.pb(edge_id[mp(b,c)]);
			if (has(edge_id,mp(c,b))) ids.pb(edge_id[mp(c,b)]);
			if (c == i) break;
			cur.pb(c);
			a = b, b = c;
		}
		sort(all(cur),greater<ll>());
		faces.eb(cur,ids);
	}
	sort(all(faces),greater<pair<vl,vl>>());
	reverse(all(faces));
	/*
	for (const auto &p: faces) {
		for (ll x: p.xx) cout << x << " ";
		cout << endl;
		for (ll x: p.yy) cout << x << " ";
		cout << endl << endl;
	}
	*/
	vvl edge_ends(m);

	ll ii = 0;
	for (const auto &p: faces) {
		for (const auto &j: p.yy) edge_ends[j].pb(ii);
		ii++;
	}
	
	//assert(sz(faces) == m+1);
	vvl adj_tree(sz(faces));
	FOR(i,0,m) {
		ll a = edge_ends[i][0], b = edge_ends[i][1];
		adj_tree[a].pb(b);
		adj_tree[b].pb(a);
	}
	
	vl col = foo.centroid_decomp(adj_tree);
	
	FOR(i,0,m+1) cout << col[i] << " \n"[i==m];

}