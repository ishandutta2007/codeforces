#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int LN = 18;
int n;
int dp[LN][N];
int depth[N];
int a , b;
int dia;
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
int main(){
	scanf("%d" , &n);
	dp[0][1] = 0;
	depth[1] = 0;
	a = 1;
	b = 1;
	dia = 0;
	for(int i = 2 ; i <= n ; ++i){
		scanf("%d" , &dp[0][i]);
		depth[i] = depth[dp[0][i]] + 1;
		for(int j = 1 ; j < LN ; ++j){
			dp[j][i] = dp[j - 1][dp[j - 1][i]];
		}
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
		printf("%d%c" , dia , " \n"[i == n]);
	}
}