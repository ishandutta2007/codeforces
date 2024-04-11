#include <bits/stdc++.h>

using namespace std;

vector<int> G[200001]; // LMAO MLE (Not here lol)
int d1[200001], d2[200001];
int x[200001];

void dfs1(int v = 1, int p = -1){
	for(auto i : G[v]){
		if(i != p){
			d1[i] = d1[v] + 1;
			dfs1(i, v);
		}
	}
}

bool vis[200001], can[200001];
bool dfs2(int v = 1, int p = -1){
	if(G[v].size() == 1 && v != 1){
		return true;
	}
	bool res = false;
	for(auto i : G[v]){
		if(i != p && can[i]){
			res |= dfs2(i, v);
		}
	}
	return res;
}

int dfs3(int v = 1, int p = -1){
	int res = 0;
	for(auto i : G[v]){
		if(i != p){
			if(can[i]){
				res += dfs3(i, v);
			}else{
				res++;
			}
		}
	}
	return res;
}


void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> x[i];
	}
	for(int i = 1; i <= n; i++){
		G[i].clear();
	}
	fill(d1, d1 + n + 1, (1 << 30));
	fill(d2, d2 + n + 1, (1 << 30));
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	d1[1] = 0;
	dfs1();
	queue<int> Q;
	for(int i = 0; i < k; i++){
		Q.push(x[i]);
		d2[x[i]] = 0;
	}
	fill(vis, vis + n + 1, 0);
	while(Q.size()){
		int fi = Q.front(); Q.pop();
		if(vis[fi]) continue;
		vis[fi] = true;
		for(auto i : G[fi]){
			if(!vis[i]){
				Q.push(i);
				d2[i] = min(d2[i], d2[fi] + 1);
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		can[i] = d1[i] < d2[i];
	}
	
	if(dfs2()){
		cout << -1 << endl;
	}else{
		cout << dfs3() << endl;
	}
}
int main(){
	int t;
	cin >> t;
	while(t--) solve();
}