#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge{
	int u, v, w;
	bool active = true;
	bool operator< (const Edge& o) const{
		return w < o.w;
	}
};

struct DSU{
	vector<int> p, sz;
	void init(int n){
		p.resize(n + 1);
		sz.resize(n + 1);
		for(int i = 0; i <= n; i++){
			p[i] = i;
			sz[i] = 1;
		}
	}

	int root(int x){
		if(p[x] == x) return x;
		return p[x] = root(p[x]);
	}

	bool join(int u, int v){
		int x = root(u), y = root(v);
		if(x == y) return false;
		if(sz[x] < sz[y]) swap(x, y);
		sz[x] += sz[y];
		p[y] = x;
		return true; 
	}
} dsu;

int n, m;
bool test(vector<Edge>& E){
	dsu.init(n);
	int cnt = 0;
	for(int i = 0; i < m; i++){
		if(E[i].active) cnt += dsu.join(E[i].u, E[i].v);
	}
	return cnt == n - 1;
}

void solve(){
	cin >> n >> m;
	vector<Edge> E;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		E.push_back({u, v, w});
	}
	sort(E.begin(), E.end());

	int ans = 0;
	for(int j = 29; j >= 0; j--){
		vector<int> disable;
		for(int i = 0; i < m; i++){
			if((E[i].w & (1 << j)) && E[i].active) disable.push_back(i), E[i].active = false;
		}
		if(!test(E)){
			ans |= (1 << j);
			for(int i : disable){
				E[i].active = true;
			}
		}
	}
	cout << ans << endl;
}

int32_t main(){
	int t; cin >> t;
	while(t--) solve();
}