#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int C = 15;
const int mod = 1e9 + 7;
int n , m;
int a , b;
vector < int > v[N];
int k , cnt;
int dp[N][3][C];
int tmp[C];
void dfs(int node , int parent){
	for(int next : v[node]){
		if(next == parent){
			continue;
		}
		dfs(next , node);
	}
	dp[node][1][0] = k - 1;
	for(int next : v[node]){
		if(next == parent){
			continue;
		}
		memset(tmp , 0 , sizeof(tmp));
		for(int i = 0 ; i <= cnt ; ++i){
			for(int j = cnt ; j >= i ; --j){
				tmp[j] = (tmp[j] + 1LL * dp[next][0][i] * dp[node][1][j - i]) % mod;
			}
		}
		for(int i = 0 ; i <= cnt ; ++i){
			dp[node][1][i] = tmp[i];
		}
	}
	dp[node][2][0] = m - k;
	for(int next : v[node]){
		if(next == parent){
			continue;
		}
		memset(tmp , 0 , sizeof(tmp));
		for(int i = 0 ; i <= cnt ; ++i){
			for(int j = cnt ; j >= i ; --j){
				tmp[j] = (tmp[j] + 1LL * dp[next][2][i] * dp[node][2][j - i]) % mod;
			}
		}
		for(int i = 0 ; i <= cnt ; ++i){
			dp[node][2][i] = tmp[i];
		}
	}
	dp[node][0][1] = 1;
	for(int next : v[node]){
		if(next == parent){
			continue;
		}
		memset(tmp , 0 , sizeof(tmp));
		for(int i = 0 ; i <= cnt ; ++i){
			for(int j = cnt ; j >= i ; --j){
				tmp[j] = (tmp[j] + 1LL * dp[next][1][i] * dp[node][0][j - i]) % mod;
			}
		}
		for(int i = 0 ; i <= cnt ; ++i){
			dp[node][0][i] = tmp[i];
		}
	}
	for(int i = 0 ; i <= cnt ; ++i){
		int b = dp[node][0][i];
		int a = dp[node][1][i];
		int c = dp[node][2][i];
		dp[node][1][i] = a;
		dp[node][0][i] = (1LL * a + 1LL * b + 1LL * c) % mod;
		dp[node][2][i] = (a + c) % mod;
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	scanf("%d %d" , &k , &cnt);
	dfs(1 , 0);
	int ans = 0;
	for(int i = 0 ; i <= cnt ; ++i){
		ans += dp[1][0][i];
		ans %= mod;
	}
	printf("%d\n" , ans);
}