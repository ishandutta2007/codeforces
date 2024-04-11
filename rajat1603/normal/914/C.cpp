#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
const int mod = 1e9 + 7;
char str[N];
int n;
int k;
int dp1[N];
int dp2[N][2][N];
int solve(int pos , bool ok , int sum){
	if(pos > n){
		return dp1[sum] == k - 1;
	}
	if(dp2[pos][ok][sum] != -1){
		return dp2[pos][ok][sum];
	}
	int res = 0;
	int dig = str[pos] - '0';
	for(int j = 0 ; j < 2 ; ++j){
		if(!ok && j > dig){
			continue;
		}
		res += solve(pos + 1 , ok | (j < dig) , sum + j);
		res -= (res >= mod) * mod;
	}
	return dp2[pos][ok][sum] = res;
}
int main(){
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	scanf("%d" , &k);
	if(k == 0){
		printf("1\n");
		return 0;
	}
	if(k == 1){
		printf("%d\n" , n - 1);
		return 0;
	}
	dp1[1] = 0;
	for(int i = 2 ; i < N ; ++i){
		dp1[i] = dp1[__builtin_popcount(i)] + 1;
	}
	memset(dp2 , -1 , sizeof(dp2));
	printf("%d\n" , solve(1 , 0 , 0));
}