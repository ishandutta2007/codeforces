#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
const int mod = 1e9 + 7;
int n;
char str[N][3];
int dp[N][N];
int solve(int pos , int nest){
	if(nest < 0){
		return 0;
	}
	if(pos > n){
		return 1;
	}
	if(dp[pos][nest] != -1){
		return dp[pos][nest];
	}
	int res = solve(pos , nest - 1);
	if(str[pos][0] == 's'){
		res += solve(pos + 1 , nest);
	}
	else{
		res += solve(pos + 1 , nest + 1);
		res -= solve(pos + 1 , nest);
	}
	if(res >= mod){
		res -= mod;
	}
	if(res < 0){
		res += mod;
	}
	return dp[pos][nest] = res;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str[i]);
	}
	memset(dp , -1 , sizeof(dp));
	printf("%d\n" , solve(1 , 0));
}