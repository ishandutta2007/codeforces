#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
int arr[N];
vector < int > v[N];
int dp[N][2];
inline int inv(int a){
	int b = mod - 2;
	int res = 1;
	while(b){
		if(b & 1){
			res = (1LL * res * a) % mod;
		}
		a = (1LL * a * a) % mod;
		b >>= 1;
	}
	return res;
}
void dfs(int node){
	int prod = 1;
	for(int next : v[node]){
		dfs(next);
		prod = (1LL * prod * (dp[next][0] + dp[next][1])) % mod;
	}
	if(arr[node]){
		dp[node][0] = 0;
		dp[node][1] = prod;
	}
	else{
		dp[node][0] = prod;
		dp[node][1] = 0;
		for(int next : v[node]){
			dp[node][1] = (dp[node][1] + 1LL * ((1LL * prod * inv(dp[next][0] + dp[next][1])) % mod) * dp[next][1]) % mod;
		}
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; ++i){
		int par;
		scanf("%d" , &par);
		v[par + 1].emplace_back(i + 1);
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	dfs(1);
	printf("%d\n" , dp[1][1]);
}