#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 17;
int n , q;
int a , b;
vector < int > v[N];
int depth[N];
int dp[LN][N];
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
bool isanc(int top , int bot){
	return (tin[top] <= tin[bot]) && (tout[bot] <= tout[top]);
}
int lca(int a , int b){
	int dif = depth[a] - depth[b];
	if(dif < 0){
		swap(a , b);
		dif *= -1;
	}
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
	return depth[a] + depth[b] - 2 * depth[lca(a , b)] + 1;
}
int solve(int s , int t , int f){
	if(isanc(f , s) ^ isanc(f , t)){
		return 1;
	}
	if(isanc(f , s) && isanc(f , t)){
		return dist(lca(s , t) , f);
	}
	int tmp1 = lca(s , f);
	int tmp2 = lca(t , f);
	if(tmp1 == tmp2){
		return dist(lca(s , t) , f);
	}
	return depth[f] - max(depth[tmp1] , depth[tmp2]) + 1;
}
int main(){
	scanf("%d %d" , &n , &q);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d" , &a);
		b = i + 1;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dfs(1 , 0);
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
	for(int i = 1 ; i <= q ; ++i){
		int a , b , c;
		scanf("%d %d %d" , &a , &b , &c);
		int res = 0;
		res = max(res , solve(a , b , c));
		res = max(res , solve(a , c , b));
		res = max(res , solve(b , a , c));
		res = max(res , solve(b , c , a));
		res = max(res , solve(c , a , b));
		res = max(res , solve(c , b , c));
		printf("%d\n" , res);
	}
}