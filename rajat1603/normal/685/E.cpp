#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int M = 2e5 + 5;
int n , m , q;
int a[M];
int b[M];
int dp[N][N];
int l[M];
int r[M];
int s[M];
int t[M];
vector < int > v[M];
int ans[M];
int main(){
	scanf("%d %d %d" , &n , &m , &q);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			dp[i][j] = m + 1;
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , a + i , b + i);
	}
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d %d %d" , l + i , r + i , s + i , t + i);
		v[l[i]].emplace_back(i);
	}
	for(int i = m ; i >= 1 ; --i){
		int a = ::a[i];
		int b = ::b[i];
		dp[a][b] = min(dp[a][b] , i);
		dp[b][a] = min(dp[b][a] , i);
		for(int j = 1 ; j <= n ; ++j){
			dp[a][j] = min(dp[a][j] , dp[b][j]);
		}
		for(int j = 1 ; j <= n ; ++j){
			dp[b][j] = min(dp[b][j] , dp[a][j]);
		}
		for(int idx : v[i]){
			ans[idx] = dp[s[idx]][t[idx]];
		}
	}
	for(int i = 1 ; i <= q ; ++i){
		printf((ans[i] <= r[i]) ? "Yes\n" : "No\n");
	}
}