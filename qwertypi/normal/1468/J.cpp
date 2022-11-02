#include <bits/stdc++.h>
#define int long long
using namespace std;

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

struct Edge{
	int u, v, w;
	bool operator< (const Edge& o) const{
		return w < o.w;
	}
};

vector<Edge> E;
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	E.clear();
	dsu.init(n);
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		E.push_back({u, v, w});
	}
	sort(E.begin(), E.end());
	int ans1 = (1LL << 60);
	int cc = n;
	for(auto i : E){
		if(i.w <= k){
			ans1 = min(ans1, k - i.w);
			cc -= dsu.join(i.u, i.v);
		}
	}
	int ans2 = 0;
	for(auto i : E){
		if(i.w > k){
			ans1 = min(ans1, i.w - k);
			if(dsu.join(i.u, i.v)){
				ans2 += i.w - k;
			}
		}
	}
	if(ans2 != 0){
		cout << ans2 << endl;
	}else{
		cout << ans1 << endl;
	}
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}