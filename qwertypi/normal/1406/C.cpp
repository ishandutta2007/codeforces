#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G(100001);
int p[100001];
int sz[100001];
void dfs(int v = 0, int _p = -1){
	int _sz = 1;
	for(auto i : G[v]){
		if(i != _p){
			dfs(i, v);
			p[i] = v;
			_sz += sz[i];
		}
	}
	sz[v] = _sz;
}

int n;
vector<int> gs;
void g(int v = 0, int _p = -1){
	// cout << v << endl;
	bool red = false;
	for(auto i : G[v]){
		if(i != _p && sz[i] > n / 2){
			red = true;
			return g(i, v);
		}
	}
	
	if(!red){
		gs.push_back(v);
		for(auto i : G[v]){
			if(sz[i] == n / 2 && n % 2 == 0) gs.push_back(i);
		}
		return;
	}
}

int dfs_end(int v, int _p = -1){
	for(auto i : G[v]){
		if(i != _p){
			return dfs_end(i, v); 
		}
	}
	return v;
}

void answer(int a, int b, int c, int d){
	cout << a + 1 << ' ' << b + 1 << endl << c + 1 << ' ' << d + 1 << endl; 
}
void solve(){
	gs.clear();
	cin >> n;
	for(int i = 0; i < n; i++){
		G[i].clear();
	}
	p[0] = -1;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs();
	g();
	if(gs.size() == 1){
		answer(1, p[1], 1, p[1]); 
		return; 
	}else{
		if(gs.size() >= 3) assert(0 == 1);
		if(p[gs[1]] == gs[0]) swap(gs[0], gs[1]);
		// cout << gs[0] << ' ' << gs[1] << endl;
		int v = dfs_end(gs[0], gs[1]);
		// cout << v << endl;
		answer(v, p[v], v, gs[1]);
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}