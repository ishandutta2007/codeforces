#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
vector < int > v[N];
int dp[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		v[i].emplace_back(arr[i]);
		if(i < n){
			v[i].emplace_back(i + 1);
		}
		if(i > 1){
			v[i].emplace_back(i - 1);
		}
	}
	dp[1] = 0;
	queue < int > q;
	q.push(1);
	for(int i = 2 ; i <= n ; ++i){
		dp[i] = 1e9;
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int next : v[node]){
			if(dp[next] > dp[node] + 1){
				dp[next] = dp[node] + 1;
				q.push(next);
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , dp[i] , " \n"[i == n]);
	}
}