#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n;
int dp[N][N];
int solve(int pos , int allowed){
	if(pos >= allowed){
		return 0;
	}
	if(dp[pos][allowed] != -1){
		return dp[pos][allowed];
	}
	int res = 0;
	for(int i = n ; i > pos ; --i){
		res = max(res , solve(pos + 1 , min(allowed , i)) + n - i + 1);
	}
	return dp[pos][allowed] = res;
}
int main(){
	scanf("%d" , &n);
	memset(dp , -1 , sizeof(dp));
	printf("%d\n" , solve(0 , n + 1));
}