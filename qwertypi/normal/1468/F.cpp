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

void solve(){
	int n;
	cin >> n;
	map<pair<int, int>, int> M;
	for(int i = 0; i < n; i++){
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		int dx = u - x, dy = v - y;
		int g = abs(__gcd(dx, dy));
		dx /= g; dy /= g; 
		M[{dx, dy}]++;
	}
	long long ans = 0;
	for(auto i : M){
		if(M.find({-i.first.first, -i.first.second}) != M.end()){
			ans += (long long) i.second * M[{-i.first.first, -i.first.second}];
		}
	}
	ans /= 2;
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}