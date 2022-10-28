#include "bits/stdc++.h"
using namespace std;
const int N = 205;
const int M = 30 * N;
int dp[N][M];
int n , k;
long long arr[N];
int ans;
int get(long long val , int p){
	int res = 0;
	while(val % p == 0){
		++res;
		val /= p;
	}
	return res;
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			dp[i][j] = -64 * N;
		}
	}
	dp[0][0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld" , arr + i);
		int pw2 = get(arr[i] , 2);
		int pw5 = get(arr[i] , 5);
		for(int j = min(k , i) ; j >= 1 ; --j){
			for(int l = n * 30 ; l >= pw5 ; --l){
				dp[j][l] = max(dp[j][l] , dp[j - 1][l - pw5] + pw2);
			}
		}
	}
	for(int l = n * 30 ; l >= 0 ; --l){
		ans = max(ans , min(l , dp[k][l]));
	}
	printf("%d\n" , ans);
}