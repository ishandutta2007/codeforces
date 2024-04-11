#include "bits/stdc++.h"
using namespace std;
const int N = 705;
const int mod = 1e9 + 7;
char str[N];
int n;
int ans , cur;
int dp[N][2][10][N];
int solve(int pos , bool pre , int dig , int lft){
	if(pos == n + 1){
		return !lft;
	}
	if(dp[pos][pre][dig][lft] != -1){
		return dp[pos][pre][dig][lft];
	}
	int val = str[pos] - '0';
	int res = 0;
	for(int i = 0 ; i < 10 ; ++i){
		if(!pre && i > val){
			continue;
		}
		res += solve(pos + 1 , pre | (i < val) , dig , max(0 , lft - (i >= dig)));
		res -= (res >= mod) * mod;
	}
	return dp[pos][pre][dig][lft] = res;
}
int main(){
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	cur = 1;
	memset(dp , -1 , sizeof(dp));
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j < 10 ; ++j){
			ans = (ans + 1LL * cur * solve(1 , 0 , j , i)) % mod;
		}
		cur = (cur * 10LL) % mod;
	}
	printf("%d\n" , ans);
}