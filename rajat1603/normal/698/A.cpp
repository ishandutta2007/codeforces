#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
int arr[N];
int gym[N];
int contest[N];
int dp[N][3];
int solve(int pos , int last){//0 nothing , 1 contest , 2 gym
	if(pos > n){
		return 0;
	}
	if(dp[pos][last] != -1){
		return dp[pos][last];
	}
	int res = 1 + solve(pos + 1 , 0);
	if(contest[pos] && (last != 1)){
		res = min(res , solve(pos + 1 , 1));
	}
	if(gym[pos] && (last != 2)){
		res = min(res , solve(pos + 1 , 2));
	}
	return dp[pos][last] = res;
}
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; ++i){
		cin >> arr[i];
		if(arr[i] % 2 == 1){
			contest[i] = 1;
		}
		if(arr[i] >= 2){
			gym[i] = 1;
		}
	}
	memset(dp , -1 , sizeof(dp));
	cout << solve(1 , 0);
}