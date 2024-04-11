#include "bits/stdc++.h"
using namespace std;
const int N = 86;
const int inf = 1e8 + 8;
int n , k;
int m;
int a , b , c;
int arr[N][N];
int dp[N][N][N][N];
int solve(int l , int r , int idx , int done){
	if(done >= k){
		return 0;
	}
	if(dp[l][r][idx][done] != -1){
		return dp[l][r][idx][done];
	}
	int res = inf;
	for(int i = l ; i <= r ; ++i){
		if(i != idx && arr[idx][i] < inf){
			if(i < idx){
				res = min(res , solve(l , idx - 1 , i , done + 1) + arr[idx][i]);
			}
			else{
				res = min(res , solve(idx + 1 , r , i , done + 1) + arr[idx][i]);
			}
		}
	}
	return dp[l][r][idx][done] = res;
}
int main(){
	scanf("%d %d" , &n , &k);
	scanf("%d" , &m);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			arr[i][j] = inf;
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , &a , &b , &c);
		arr[a][b] = min(arr[a][b] , c);
	}
	int ans = inf;
	memset(dp , -1 , sizeof(dp));
	for(int i = 1 ; i <= n ; ++i){
		ans = min(ans , solve(1 , n , i , 1));
	}
	if(ans >= inf){
		ans = -1;
	}
	printf("%d\n" , ans);
}