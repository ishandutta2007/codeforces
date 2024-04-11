#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int M = 20;
const int K = 5;
int n , k;
int arr[N][K];
int cnt[1 << K];
int dp[M][15][15][15][15][2];
bool solve(int mask , int a , int b , int c , int d , bool done){
	if(mask == 16){
		return (a >= 0) && (b >= 0) && (c >= 0) && (d >= 0) && done;
	}
	if(dp[mask][a + 7][b + 7][c + 7][d + 7][done] != -1){
		return dp[mask][a + 7][b + 7][c + 7][d + 7][done];
	}
	bool res = 0;
	int add1 = ((mask >> 0) & 1) ? -1 : 1;
	int add2 = ((mask >> 1) & 1) ? -1 : 1;
	int add3 = ((mask >> 2) & 1) ? -1 : 1;
	int add4 = ((mask >> 3) & 1) ? -1 : 1;
	int na = a;
	int nb = b;
	int nc = c;
	int nd = d;
	int ndone = done;
	for(int i = 0 ; i <= cnt[mask] ; ++i){
		if(max(max(na , nb) , max(nc , nd)) > 7){
			break;
		}
		if(min(min(na , nb) , min(nc , nd)) < -7){
			break;
		}
		if(solve(mask + 1 , na  , nb , nc , nd , ndone)){
			res = 1;
			break;
		}
		ndone = 1;
		na += add1;
		nb += add2;
		nc += add3;
		nd += add4;
	}
	return dp[mask][a + 7][b + 7][c + 7][d + 7][done] = res;
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		int mask = 0;
		for(int j = 0 ; j < k ; ++j){
			scanf("%d" , &arr[i][j]);
			mask += (1 << j) * (arr[i][j]);
		}
		++cnt[mask];
	}
	memset(dp , -1 , sizeof(dp));
	printf(solve(0 , 0 , 0 , 0 , 0 , 0) ? "YES\n" : "NO\n");
}