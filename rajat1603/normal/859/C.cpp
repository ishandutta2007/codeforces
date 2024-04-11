#include "bits/stdc++.h"
using namespace std;
const int N = 55;
int n;
int arr[N];
int dp[N];
int tot;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		tot += arr[i];
	}
	for(int i = n ; i >= 1 ; --i){
		dp[i] = max(dp[i + 1] - arr[i] , arr[i] - dp[i + 1]);
	}
	int bob = (tot + dp[1]) / 2;
	printf("%d %d\n" , tot - bob , bob);
}