//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 4e5 + 10;
int sz[maxn],
	h[maxn],
	frm[maxn],
	too[maxn],
	xxx[maxn],
	n, m;
bool mark[maxn];
vector<int> adj[maxn];

int dfs(int u, int p = -1){
	mark[u] = true;
	int mn = maxn;
	sz[u] = 1;
	for(auto e : adj[u]){
		int v = frm[e]^too[e]^u;
		if(!mark[v]){
			h[v] = h[u] + 1;
			int val = dfs(v, u);
			if(val <= h[u])
				sz[u] += sz[v];
			smin(mn, val);
		}
		else if(v != p)
			smin(mn, h[v]);
	}
	return mn;
}

void dfs2(int u, int p = -1){
	mark[u] = true;
	for(auto e : adj[u]){
		int v = frm[e] ^ too[e] ^ u;
		if(!mark[v]){
			dfs2(v, u);
			xxx[e] = v;
		}
		else if(v != p)
			xxx[e] = u;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		frm[i] = fi;
		too[i] = se;
		adj[fi].PB(i);
		adj[se].PB(i);
	}
	dfs(0);
	cout << *max_element(sz, sz + n) << '\n';
	memset(mark, false, sizeof mark);
	int u = max_element(sz, sz + n) - sz;
	dfs2(u);
	for(int i = 0; i < m; i++)
		cout << (xxx[i])+1 << ' ' << (frm[i]^too[i]^xxx[i])+1 << '\n';
	return 0;
}