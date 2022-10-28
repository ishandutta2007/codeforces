#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int LN = 18;
int n , k;
int arr[N];
int a , b;
vector < int > v[N];
int depth[N];
int dp[LN][N];
int tin[N];
long long ans;
int timer = 0;
void dfs(int node , int parent){
	depth[node] = depth[parent] + 1;
	dp[0][node] = parent;
	tin[node] = ++timer;
	for(int next : v[node]){
		if(next != parent){
			dfs(next , node);
		}
	}
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
int dist(int a , int b){
	return depth[a] + depth[b] - 2 * depth[lca(a , b)];
}
int main(){
	scanf("%d %d" , &n , &k);
	k += k;
	for(int i = 1 ; i <= k ; ++i){
		scanf("%d" , arr + i);
		//arr[i] = i;
	}
	for(int i = 1 ; i < n ; ++i){
		//a = i;
		//b = i + 1;
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
	sort(arr + 1 , arr + 1 + k , [](int a , int b){
		return tin[a] < tin[b];
	});
	for(int i = 1 ; i <= (k >> 1) ; ++i){
		ans += dist(arr[i] , arr[i + (k >> 1)]);
	}
	printf("%lld\n" , ans);
}