#include "bits/stdc++.h"
using namespace std;
const int N = 16;
const int M = 255;
const int mod = 1e9 + 7;
int n , m;
char inp[M][M];
int arr[M];
int cover[M][1 << N];
int dp[M][1 << N][2];
int solve(int col , int mask , bool rip){
	if(col > m){
		return 1;
	}
	if(dp[col][mask][rip] != -1){
		return dp[col][mask][rip];
	}
	long long res = 0;
	int newmask = mask & arr[col];
	for(int i = arr[col] ; i ; i = (i - 1) & arr[col]){
		int tmp = newmask | cover[col][i];
		if(tmp == arr[col]){
			res += solve(col + 1 , newmask | i , rip);
		}
		else if(!rip){
			int lft = tmp ^ arr[col];
			if((lft & -lft) == lft){
				res += solve(col + 1 , newmask | i , 1);
			}
		}
	}
	if(newmask == arr[col]){
		res += solve(col + 1 , newmask , rip);
	}
	else if(!rip){
		int lft = newmask ^ arr[col];
		if((lft & -lft) == lft){
			res += solve(col + 1 , newmask , 1);
		}
	}
	return dp[col][mask][rip] = res % mod;
}
void pre(){
	for(int col = 1 ; col <= m ; ++col){
		for(int i = 0 ; i < (1 << n) ; ++i){
			cover[col][i] = 0;
			int cur = 0;
			for(int j = 0 ; j < n ; ++j){
				if((i >> j) & 1){
					cur = 1;
				}
				if(!((arr[col] >> j) & 1)){
					cur = 0;
				}
				if(cur){
					cover[col][i] |= 1 << j;
				}
			}
		}
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , inp[i] + 1);
	}
	memset(arr , 0 , sizeof(arr));
	if(n <= m){
		for(int i = 1 ; i <= n ; ++i){
			for(int j = 1 ; j <= m ; ++j){
				if(inp[i][j] == '.'){
					arr[j] |= 1 << (i - 1);
				}
			}
		}
	}
	else{
		for(int i = 1 ; i <= n ; ++i){
			for(int j = 1 ; j <= m ; ++j){
				if(inp[i][j] == '.'){
					arr[i] |= 1 << (j - 1);
				}
			}
		}
		swap(n , m);
	}
	pre();
	memset(dp , -1 , sizeof(dp));
	printf("%d\n" , solve(1 , 0 , 0));
}