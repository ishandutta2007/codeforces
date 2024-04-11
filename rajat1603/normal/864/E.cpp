#include "bits/stdc++.h"
using namespace std;
const int N = 105;
const int D = 2e3 + 3;
int n;
pair < pair < int , int > , pair < int , int > > arr[N];
int dp[N][D];
int solve(int pos , int t){
	if(pos > n || t >= arr[n].first.first){
		return 0;
	}
	if(dp[pos][t] != -1){
		return dp[pos][t];
	}
	int res = solve(pos + 1 , t);
	if(t + arr[pos].second.first < arr[pos].first.first){
		res = max(res , solve(pos + 1 , t + arr[pos].second.first) + arr[pos].second.second);
	}
	return dp[pos][t] = res;
}
vector < int > ans;
void go(int pos , int t){
	if(pos > n || t >= arr[n].first.first){
		return;
	}
	if(solve(pos + 1 , t) == solve(pos , t)){
		go(pos + 1 , t);
		return;
	}
	ans.emplace_back(arr[pos].first.second);
	go(pos + 1 , t + arr[pos].second.first);
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %d" , &arr[i].second.first , &arr[i].first.first , &arr[i].second.second);
		arr[i].first.second = i;
	}
	sort(arr + 1 , arr + 1 + n);
	memset(dp , -1 , sizeof(dp));
	printf("%d\n" , solve(1 , 0));
	go(1 , 0);
	printf("%d\n" , int(ans.size()));
	for(int x : ans){
		printf("%d " , x);
	}
	printf("\n");
}