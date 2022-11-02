#include <bits/stdc++.h>
#define inf (1 << 30)
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
 
const int N = 200013;
vector<int> G[N], H[N];
int d[N], deg[N];
bool vis[N];
 
struct DS{
	int ans = inf;
	int cnt = 0;
	void add(int v){
		ans = min(ans, v - cnt);
		cnt++;
	}
	int qry(){
		return ans;
	}
} ds[N];
 
void dfs(int v){
	vis[v] = true;
	vector<int> ds;
	for(auto i : G[v]){
		ds.push_back(d[i]);
	}
	sort(ds.begin(), ds.end());
	for(int i = 0; i < ds.size(); i++){
		d[v] = min(d[v], ds[i] - i + deg[v]);
	}
}
 
int32_t main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n - 1; i++) d[i] = inf;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		deg[u]++;
		G[u].push_back(v);
		H[v].push_back(u);
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, n - 1});
	while(pq.size()){
		pii t = pq.top(); pq.pop();
		if(vis[t.se]) continue;
		dfs(t.se);
		for(auto i : H[t.se]){
			ds[i].add(d[t.se]);
			pq.push({ds[i].qry() + deg[i], i});
		}
	}
	cout << d[0] << endl;
}