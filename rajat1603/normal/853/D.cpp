#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int D = 41;
int n;
int arr[N];
int dp[N][D];
int solve(int pos , int cur){
	if(pos > n){
		return 0;
	}
	if(cur >= D){
		return N * D;
	}
	if(dp[pos][cur] != -1){
		return dp[pos][cur];
	}
	return dp[pos][cur] = min(solve(pos + 1 , cur + arr[pos] / 10) + arr[pos] , solve(pos + 1 , max(0 , cur - arr[pos])) + max(0 , arr[pos] - cur));
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		arr[i] /= 100;
	}
	memset(dp , -1 , sizeof(dp));
	printf("%d\n" , solve(1 , 0) * 100);
}