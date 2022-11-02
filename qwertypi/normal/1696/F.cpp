#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
bool d[101][101][101];

const int N = 101;
struct DSU{
	int p[N], sz[N];
	void init(int n){
		for(int i = 0; i <= n; i++) p[i] = i, sz[i] = 1;
	}
	int f(int x){
		return x == p[x] ? x : p[x] = f(p[x]);
	}
	bool g(int x, int y){
		x = f(x), y = f(y);
		if(x == y) return false;
		if(sz[x] < sz[y]) swap(x, y);
		return sz[x] += sz[y], p[y] = x, true;
	}
};

vector<int> vc[101][101];

vector<pii> E;
bool mvis[101], vis[101];
bool failed = false;

void dfs(int v, int p){
	E.push_back({v, p});
	vis[v] = true;
	for(auto i : vc[v][p]){
		if(i != p && i != v){
			if(vis[i]) return void(failed = true);
			dfs(i, v);
			if(failed) return;
		}
	}
}

vector<int> G[101];

int d2[101][101];

void dfs2(int v, int r, int p = -1, int dis = 0){
	d2[r][v] = dis;
	for(auto i : G[v]){
		if(i != p){
			dfs2(i, r, v, dis + 1);
		}
	}
}

int n;
bool check(vector<pii> E){
	for(int i = 0; i < n; i++) G[i].clear();
	for(auto i : E){
		G[i.first].push_back(i.second);
		G[i.second].push_back(i.first);
	}
	DSU dsu; dsu.init(n);
	for(auto i : E){
		dsu.g(i.first, i.second);
	}
	for(int i = 1; i < n; i++){
		if(dsu.f(i) != dsu.f(0)){
			return false;
		}
	}
	if(E.size() != n - 1){
		return false;
	}
	for(int i = 0; i < n; i++){
		dfs2(i, i);
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int k = 0; k < n; k++){
				if((d2[i][k] == d2[j][k]) ^ d[i][j][k]) return false;
			}
		}
	} 
	return true;
}

void output(vector<pii> E){
	cout << "Yes" << endl;
	for(auto i : E){
		cout << i.first + 1 << ' ' << i.second + 1 << endl;
	}
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			vc[i][j].clear();
		}
	}
	fill(mvis, mvis + n, 0);
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= n - 1 - i; j++){
			string s; cin >> s;
			for(int k = 0; k < n; k++){
				d[i + j][i][k] = d[i][i + j][k] = s[k] == '1';
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int k = 0; k < n; k++){
			d[i][i][k] = 1;
		}
	}
	
	for(int k = 0; k < n; k++){
		DSU dsu;
		dsu.init(n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(d[i][j][k]) dsu.g(i, j);
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(d[i][j][k] ^ (dsu.f(i) == dsu.f(j))){
					cout << "No" << endl;
					return;
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(d[i][j][k]){
					vc[k][i].push_back(j);
				}
			}
		}
	}
	fill(mvis, mvis + n, 0);
	for(int i = 1; i < n; i++){
		vis[0] = true; failed = false;
		E.clear();
		if(!mvis[i]){
			fill(vis + 1, vis + n, 0);
			int mai = i;
			for(auto j : vc[0][i]){
				if(j != 0) dfs(j, 0);
				mvis[j] = true;
			}
		}
		if(!failed && check(E)){
			output(E);
			return;
		}
	}
	cout << "No" << endl;
	return;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}