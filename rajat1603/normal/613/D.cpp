#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 17;
int n;
int a , b;
vector < int > v[N];
int q;
int k;
int arr[N + N];
int dp[LN][N];
int depth[N];
int tin[N];
int tout[N];
int timer;
void dfs(int node , int parent){
	depth[node] = depth[parent] + 1;
	dp[0][node] = parent;
	tin[node] = ++timer;
	for(int next : v[node]){
		if(next != parent){
			dfs(next , node);
		}
	}
	tout[node] = timer;
}
int lca(int a , int b){
	if(depth[a] < depth[b]){
		swap(a , b);
	}
	int dif = depth[a] - depth[b];
	for(int i = 0 ; i < LN ; ++i){
		if(dif & (1 << i)){
			a = dp[i][a];
		}
	}
	if(a != b){
		for(int i = LN - 1 ; i >= 0 ; --i){
			if(dp[i][a] != dp[i][b]){
				a = dp[i][a];
				b = dp[i][b];
			}
		}
		a = dp[0][a];
	}
	return a;
}
int mark[N];
vector < int > tree[N];
bool isanc(int top , int bottom){
	return (tin[top] <= tin[bottom]) && (tout[bottom] <= tout[top]);
}
pair < int , int > dfs1(int node){
	if(v[node].size() == 0){
		return {mark[node] , 0};
	}
	int res1 = 0;
	int res2 = 0;
	int cnt = 0;
	for(int next : tree[node]){
		auto res = dfs1(next);
		if(mark[node]){
			res2 += res.first + res.second;
		}
		else{
			cnt += res.first;
			res2 += res.second;
		}
	}
	if(mark[node]){
		return {1 , res2};
	}
	else{
		if(cnt > 1){
			return {0 , 1 + res2};
		}
		else{
			return {cnt , res2};
		}
	}
}
void solve(){
	for(int i = 1 ; i <= k ; ++i){
		mark[arr[i]] = 1;
	}
	bool rekt = 0;
	for(int i = 1 ; i <= k ; ++i){
		if(mark[dp[0][arr[i]]]){
			rekt = 1;
			break;
		}
	}
	if(rekt){
		for(int i = 1 ; i <= k ; ++i){
			mark[arr[i]] = 0;
		}
		printf("-1\n");
		return;
	}
	sort(arr + 1 , arr + 1 + k , [](int a , int b){
		return tin[a] < tin[b];
	});
	int _k = k;
	for(int i = 1 ; i < _k ; ++i){
		arr[++k] = lca(arr[i] , arr[i + 1]);
	}
	sort(arr + 1 , arr + 1 + k);
	k = unique(arr + 1 , arr + 1 + k) - arr - 1;
	sort(arr + 1 , arr + 1 + k , [](int a , int b){
		return tin[a] < tin[b];
	});
	stack < int > s;
	s.push(arr[1]);
	for(int i = 2 ; i <= k ; ++i){
		while(!isanc(s.top() , arr[i])){
			s.pop();
		}
		tree[s.top()].emplace_back(arr[i]);
		s.push(arr[i]);
	}
	printf("%d\n" , dfs1(arr[1]).second);
	for(int i = 1 ; i <= k ; ++i){
		tree[arr[i]].clear();
		mark[arr[i]] = 0;
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dfs(1 , 0);
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
	scanf("%d" , &q);
	while(q--){
		scanf("%d" , &k);
		for(int i = 1 ; i <= k ; ++i){
			scanf("%d" , arr + i);
		}
		solve();
	}
}