#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int M = 15;
const int A = 1e5 + 5;
int n , m;
int arr[M];
int dp[M][N];
int whatn[A + 1];
int whatm[A + 1];
int main(){
	m = 10;
	for(int i = 1 ; i <= m ; ++i){
		arr[i] = 1 << (i - 1);
	}
	dp[0][0] = 1;
	for(int i = 1 ; i <= m ; ++i){
		for(int j = 0 ; j < N ; ++j){
			dp[i][j] = dp[i - 1][j];
			if(j >= arr[i]){
				dp[i][j] += dp[i][j - arr[i]];
			}
			dp[i][j] = min(dp[i][j] , A);
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		for(int j = 1 ; j <= 1000000 ; ++j){
			whatn[dp[i][j]] = j;
			whatm[dp[i][j]] = i;
		}
	}
	int a;
	scanf("%d" , &a);
	printf("%d %d\n" , whatn[a] , whatm[a]);
	for(int i = 1 ; i <= whatm[a] ; ++i){
		printf("%d " , arr[i]);
	}
	printf("\n");
}