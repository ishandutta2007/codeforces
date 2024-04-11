#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 17;
int n;
int parent[N] , type[N];
int q;
int dp[LN][N];
int sum1[N];
int sum2[N];
int depth[N];
int lca(int a , int b){
	int dif = depth[a] - depth[b];
	if(dif < 0){
		swap(a , b);
		dif *= -1;
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
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , parent + i , type + i);
		if(parent[i] != -1){
			depth[i] = depth[parent[i]] + 1;
			sum1[i] = sum1[parent[i]] + (type[i] == 0);
			sum2[i] = sum2[parent[i]] + (type[i] == 1);
			dp[0][i] = parent[i];
		}
	}
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
	scanf("%d" , &q);
	while(q--){
		int type , u , v;
		scanf("%d %d %d" , &type , &u , &v);
		int lc = lca(u , v);
		if(lc == 0){
			printf("NO\n");
			continue;
		}
		if(lc == v){
			printf("NO\n");
			continue;
		}
		if(type == 1){
			if(lc == u && sum2[v] - sum2[u] == 0){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
		else{
			if(sum1[v] - sum1[lc] == 0 && sum2[u] - sum2[lc] == 0){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}
}