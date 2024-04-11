#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int u, v, w;
	bool operator< (const Edge& o) const{
		return w < o.w;
	}
};

vector<Edge> E;

int p[200001], sz[200001];
int mx[200001];
int root(int x){
	if(p[x] == x) return x;
	return p[x] = root(p[x]);
}

bool join(int u, int v, int w){
	int x = root(u), y = root(v);
	if(x == y) return false;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	p[y] = x;
	mx[u] = max(mx[u], w);
	mx[v] = max(mx[v], w);
	return true; 
}

int ans1 = 0, ans2 = 0;
void trial(vector<Edge>& E){
	for(auto e : E){
		if(root(e.u) != root(e.v)){
			ans1++;
		}
	}
	for(auto e : E){
		ans2 += join(e.u, e.v, e.w);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		E.push_back({u, v, w});
	}
	sort(E.begin(), E.end());
	int ans = 0;
	for(int i = 0; i <= n; i++){
		p[i] = i, sz[i] = 1;
	}
	int curW = 0;
	vector<Edge> con;
	for(auto e : E){
		if(e.w == curW){
			con.push_back(e);
		}else{
			trial(con);
			con.clear();
			curW = e.w;
			con.push_back(e);
		}
	}
	trial(con);
	cout << ans1 - ans2 << endl;
}