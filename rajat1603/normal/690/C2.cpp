#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int LN = 18;
int n;
int dp[LN][N];
int depth[N];
int a , b;
int dia;
vector < int > v[N];
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
	return depth[a] + depth[b] - (depth[lca(a , b)] << 1);
}
void dfs(int node , int parent){
	for(int next : v[node]){
		if(next != parent){
			depth[next] = depth[node] + 1;
			dp[0][next] = node;
			dfs(next , node);
		}
	}
}
int main(){
	scanf("%d %d" , &n , &a);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dp[0][1] = 0;
	depth[1] = 0;
	a = 1;
	b = 1;
	dia = 0;
	dfs(1 , 0);
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
	for(int i = 2 ; i <= n ; ++i){
		int val1 = dist(i , a);
		int val2 = dist(i , b);
		if(val1 < val2){
			swap(val1 , val2);
			swap(a , b);
		}
		if(val1 > dia){
			b = i;
			dia = val1;
		}
	}
	printf("%d\n" , dia);
}