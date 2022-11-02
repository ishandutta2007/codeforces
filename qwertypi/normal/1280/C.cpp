#include <bits/stdc++.h>
#define int long long
using namespace std;
 
vector<vector<int>> G(200001);
vector<pair<pair<int, int>, int>> E; 
int dp[200001];
bool visited[200001];
 
void dfs(int root){
	visited[root] = 1;
	vector<int> next;
	for(auto i : G[root]){
		if(visited[i]){
			continue;
		}
		next.push_back(i);
	}
	if(next.size() == 0){
		dp[root] = 1;
	}else{
		int sum = 1;
		for(auto i : next){
			dfs(i);
			sum += dp[i];
		}
		dp[root] = sum;
	}
}
 
void sub(){
	int k;
	cin >> k;
	E.clear();
	for(int i = 1; i <= 2 * k; i++){
		visited[i] = 0;
		G[i].clear();
	}
	for(int i = 0; i < 2 * k - 1; i++){
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		G[v1].push_back(v2);
		G[v2].push_back(v1);
		E.push_back({{v1, v2}, w});
	}
	int root = 1;
	dfs(root);
	int ans1 = 0, ans2 = 0;
	for(auto i : E){
		int _min = min(dp[i.first.first], dp[i.first.second]);
		if(_min % 2){
			ans1 += i.second;
		}
		ans2 += min(_min, 2 * k - _min) * i.second;
	} 
	cout << ans1 << ' ' << ans2 << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}