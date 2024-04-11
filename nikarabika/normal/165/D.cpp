#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())

const int maxn = 1e5 + 85 - 69;
set<int> s[maxn];
vector<int> adj[maxn];
vector<pii> edge;
int n;
int h[maxn], comp[maxn], cmpcnt;

int elseone(int e, int v){return edge[e].L == v ? edge[e].R : edge[e].L;}

void dfs(int v, int p){
	comp[v] = cmpcnt;
	for(auto e : adj[v]){
		int u = elseone(e, v);
		if(u != p){
			h[u] = h[v] + 1;
			dfs(u, v);
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(sz(edge));
		adj[se].PB(sz(edge));
		edge.PB({fi, se});
	}
	
	int root = 1;
	for(int i = 1; i <= n; i++)
		if(sz(adj[i]) > sz(adj[root]))
			root = i;

	for(int i = 0; i < sz(adj[root]); i++){
		int v = elseone(adj[root][i], root);
		h[v] = 1;
		dfs(v, root);
		cmpcnt++;
	}

	int q;
	cin >> q;
	while(q--){
		int ty;
		cin >> ty;
		if(ty == 1){
			int eid;
			cin >> eid;
			eid--;
			int &v = edge[eid].L, &u = edge[eid].R;
			if(h[v] > h[u])
				swap(v, u);
			s[comp[u]].erase(h[v]);
		}
		else if(ty == 2){
			int eid;
			cin >> eid;
			eid--;
			int &v = edge[eid].L, &u = edge[eid].R;
			if(h[v] > h[u])
				swap(v, u);
			s[comp[u]].insert(h[v]);
		}
		else{
			int v, u;
			cin >> v >> u;
			if(h[v] > h[u])
				swap(v, u);
			if(v == root){
				if(u == root)
					cout << 0 << '\n';
				else{
					int sid = comp[u];
					if(sz(s[sid]) and (*s[sid].begin()) < h[u])
						cout << -1 << '\n';
					else
						cout << h[u] << '\n';
				}
			}
			else if(comp[v] == comp[u]){
				int sid = comp[v];
				auto it = s[sid].lower_bound(h[v]);
				if(it != s[sid].end() and (*it) < h[u])
					cout << -1 << '\n';
				else
					cout << h[u] - h[v] << '\n';
			}
			else{
				int vsid = comp[v], usid = comp[u];
				if((sz(s[vsid]) and (*s[vsid].begin()) < h[v]) or (sz(s[usid]) and (*s[usid].begin()) < h[u]))
					cout << -1 << '\n';
				else
					cout << h[v] + h[u] << '\n';
			}
		}
	}
	return 0;
}