#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[200001], p[200001], l[200001], r[200001];
int dp1[200001], dp2[200001];
vector<int> G[200001];
int ans = 0;
int dfs(int v, int p = -1){
	int acc = 0;
	for(auto i : G[v]){
		acc += dfs(i, v);
	}
	if(acc >= l[v]){
		return min(acc, r[v]);
	}else{
		ans++;
		return r[v];
	}
}

void solve(){
	ans = 0;
	int n; cin >> n;
	for(int i = 0; i < n; i++) G[i].clear();
	for(int i = 1; i < n; i++){
		cin >> p[i];
		p[i]--;
		G[p[i]].push_back(i);
	}
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
	}
	dfs(0);
	cout << ans << endl;
}
int32_t main(){
	int t;
	cin >> t;
	for(int tc = 0; tc < t; tc++){
		solve();
	}
}