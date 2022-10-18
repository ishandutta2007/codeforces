#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <bitset>
#include <iterator>
using namespace std;  
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<bool> vb;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (auto i = begin(c); i != end(c); ++i)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) (c.find(i) != end(c))
#define DBGDO(X) ({if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const int maxN = 100005;
vector<pii> ed[maxN];

int Find(int x, vi &parent, vi&height) {
	if (x != parent[x]) parent[x] = Find(parent[x], parent, height);
	return parent[x];
}

bool Union(int x, int y, vi &parent, vi&height) {
	if ((x = Find(x, parent, height)) == (y = Find(y, parent, height))) return false;
	if (height[x] > height[y]) {
		parent[y] = x;
	} else {
		parent[x] = y;
		if (height[x] == height[y]) height[y]++;
	}
	return true;
}

void dfs(int n, vvi &adj, vi &comp, int cc) {
	comp[n] = cc;
	for (const auto &to: adj[n]) {
		if (comp[to] < 0) dfs(to, adj, comp, cc);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int n, m; cin >> n >> m;
	FOR(i,0,m) {
		int a, b, c;
		cin >> a >> b >> c;
		ed[c].eb(a,b);
	}
		
	int r = sqrt(m);
	
	vector<vi> heavy;
	map<int,int> hi;
	int hc = 0;
	map<pii,int> light;
	
	FOR(c,1,m+1) {
		if (sz(ed[c]) > r) {
			vi parent(n+1), height(n+1,0);
			FOR(i,1,n+1) parent[i] = i;
			for (const auto &e: ed[c]) {
				Union(e.xx, e.yy, parent, height);
			}
			hi[c] = hc++;
			heavy.pb(parent);
		} else {
			map<int,int> ni;
			int nc = 0;
			vi in;
			vector<vi> adj(2*sz(ed[c]),vi());
			for (const auto &e: ed[c]) {
				if (!has(ni,e.xx)) ni[e.xx] = nc++, in.pb(e.xx);
				if (!has(ni,e.yy)) ni[e.yy] = nc++, in.pb(e.yy);
				adj[ni[e.xx]].pb(ni[e.yy]);
				adj[ni[e.yy]].pb(ni[e.xx]);
			}
			vi comp(nc,-1);
			int cc = 0;
			FOR(i,0,nc) {
				if (comp[i] < 0) dfs(i, adj, comp, cc), cc++;
			}
			FOR(i,0,nc) FOR(j,0,nc) {
				if (comp[i] == comp[j]) {
					light[mp(in[i],in[j])]++;
				}
			}
		}
	}

	int q; cin >> q;
	FOR(i,0,q) {
		int u, v;
		cin >> u >> v;
		int res = light[mp(u,v)];
		vi foo;
		//cerr << res << " "; 
		for (auto &parent: heavy) {
			res += (Find(u,parent,parent) == Find(v,parent,parent));
		}
		cout << res << endl;
	}
	



	


}