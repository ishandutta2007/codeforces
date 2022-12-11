#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Edge{
	int fnode;
	int tnode;
	int weight;
	int cost;
	int index;
	bool operator< (Edge V) const {
		return weight < V.weight;
	}
	
};

const int N = (int)2e5 + 9;

int pi[N];
int sz[N];

int fin(int u){
	if(u == pi[u])
		return u;
	return pi[u] = fin(pi[u]);
}

bool merge(int a, int b){
	a = fin(a);
	b = fin(b);
	if(a==b)
		return false;
	if(sz[a] > sz[b])
		swap(a, b);
	sz[b] += sz[a];
	pi[a] = b;
	return true;
}


vector<pii> T[N];
Edge E[N];

bool used[N];

const int LOG = 20;

int tin[N];
int tout[N];
int ct;

int up[N][LOG];

int mxid(int a, int b){
	if(a == -1)
		return b;
	if(b == -1)
		return a;
	return (E[a].weight > E[b].weight ? a : b);
}

int mix[N][LOG];

void dfs(int u, int par, int las){
	tin[u] = ++ ct;
	up[u][0] = par;
	mix[u][0] = las;
	for(int i = 1; i < LOG; i ++ ){
		if(up[u][i - 1] == -1)
			up[u][i] = -1;
		else
			up[u][i] = up[up[u][i - 1]][i - 1];
		mix[u][i] = mix[u][i - 1];
		if(up[u][i - 1] != -1)
			mix[u][i] = mxid(mix[u][i], mix[up[u][i - 1]][i - 1]);
	}
	for(auto x : T[u]){
		if(x.fi == par)
			continue;
		dfs(x.fi, u, x.se);
	}
	tout[u] = ct;
}

bool is_ancestor(int a, int b){
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int max_node(int a, int b){
	
	int md = -1;
	for(int i = LOG - 1; i >= 0 ; i -- ){
		if(up[a][i] == -1)
			continue;
		if(!is_ancestor(up[a][i], b)){
			md = mxid(md, mix[a][i]);
			a = up[a][i];
		}
	}
	
	for(int i = LOG - 1; i >= 0 ; i -- ){
		if(up[b][i] == -1)
			continue;
		if(!is_ancestor(up[b][i], a)){
			md = mxid(md, mix[b][i]);
			b = up[b][i];
		}
	}
	if(!is_ancestor(a, b)) md = mxid(md, mix[a][0]);
	if(!is_ancestor(b, a)) md = mxid(md, mix[b][0]);
	return md;
}

int main(){
	fastIO;
	for(int i = 0 ;i  < N; i ++ )pi[i] = i, sz[i] = 1;
	int n, m;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++ ){
		cin >> E[i].weight;
		E[i].index = i;
	} 
	for(int i = 0 ; i <m  ;i  ++ ){
		cin >> E[i].cost;
	}
	for(int i = 0 ; i < m ; i ++ ){
		cin >> E[i].fnode >> E[i].tnode;
	}
	ll S;
	cin >> S;
	sort(E, E + m);
	ll mst = 0;
	for(int i = 0 ; i < m ;i ++ ){
		if(merge(E[i].fnode, E[i].tnode)){
			mst += E[i].weight;
			used[i] = true;
			T[E[i].fnode].push_back(mp(E[i].tnode, i));
			T[E[i].tnode].push_back(mp(E[i].fnode, i));
		}
	}
	ll answ = (ll)1e15;
	dfs(1, -1, -1);
	ll curt;
	int use = -1, eras = -1;
	int id;
	for(int i = 0 ;i < m ; i ++ ){
		if(used[i]){
			if(answ > mst - S/E[i].cost){
				answ = mst - S/E[i].cost;
				use = i;
			}
		}
		else{
			curt = mst;
			id = max_node(E[i].fnode, E[i].tnode);
			curt -= E[id].weight;
			curt += E[i].weight;
			if(answ > curt - S/E[i].cost){
				answ = curt - S/E[i].cost;
				use = i;
				eras = id;
			}
		}
	}
	used[use] = true;
	E[use].weight -= S/E[use].cost;
	if(eras != -1) used[eras] = false;
	cout << answ << "\n";
	for(int i = 0 ; i < m ; i ++ ){
		if(used[i]){
			cout << E[i].index + 1 << " " << E[i].weight << "\n";
		}
	}
	return 0;
}