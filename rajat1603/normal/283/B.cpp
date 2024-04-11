#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
long long dp[N][2];
bool instack[N][2];
long long solve(long long pos , bool dir){
	if(pos <= 0 || pos > n){
		return 0;
	}
	if(pos == 1 || instack[pos][dir]){
		return -1;
	}
	if(dp[pos][dir] != -2){
		return dp[pos][dir];
	}
	instack[pos][dir] = 1;
	long long ret;
	auto tmp = solve(pos + (dir ? -arr[pos] : arr[pos]) , !dir);
	if(tmp == -1){
		ret = -1;
	}
	else{
		ret = tmp + arr[pos];
	}
	instack[pos][dir] = 0;
	return dp[pos][dir] = ret;
}
int main(){
	scanf("%d" , &n);
	for(int i = 2 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		dp[i][0] = dp[i][1] = -2;
	}
	for(int i = 1 ; i < n ; ++i){
		long long val = solve(i + 1 , 1);
		if(val == -1){
			printf("-1\n");
		}
		else{
			printf("%lld\n" , val + i);
		}
	}
}