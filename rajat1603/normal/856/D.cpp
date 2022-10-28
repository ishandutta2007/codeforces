#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int LN = 18;
int n , m;
int dp[LN][N];
vector < int > v[N];
int tin[N];
int tout[N];
int timer;
int depth[N];
void dfs(int node){
	tin[node] = ++timer;
	for(int next : v[node]){
		depth[next] = depth[node] + 1;
		dfs(next);
	}
	tout[node] = timer;
}

inline int lca(int a , int b){
	int dif = depth[a] - depth[b];
	if(dif < 0){
		swap(a , b);
		dif = -dif;
	}
	for(int i = 0 ; i < LN ; ++i){
		if((dif >> i) & 1){
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
vector < int > paths[N];
int a[N] , b[N] , c[N];
int bit[N];
void update(int idx , int val){
	while(idx <= n){
		bit[idx] += val;
		idx += idx & -idx;
	}
}
int query(int idx){
	int res = 0;
	while(idx){
		res += bit[idx];
		idx -= idx & -idx;
	}
	return res;
}

void update(int l , int r , int val){
	update(l , val);
	update(r + 1 , -val);
}

int res[N];
int sum[N];

void dfs1(int node){
	for(int next : v[node]){
		dfs1(next);
		sum[node] += res[next];
	}
	res[node] = sum[node];
	for(int path : paths[node]){
		res[node] = max(res[node] , query(tin[a[path]]) + query(tin[b[path]]) + sum[node] + c[path]);
	}
	update(tin[node] , tout[node] , sum[node] - res[node]);
}


int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 2 ; i <= n ; ++i){
		scanf("%d" , &dp[0][i]);
		v[dp[0][i]].emplace_back(i);
	}
	dfs(1);
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , a + i , b + i , c + i);
		paths[lca(a[i] , b[i])].emplace_back(i);
	}
	dfs1(1);
	printf("%d\n" , res[1]);
}