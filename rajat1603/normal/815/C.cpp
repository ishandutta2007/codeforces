#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
int n , b;
int c[N] , d[N];
int par[N];
vector < int > v[N];
int dp[N][2][N];
multiset < int > s[N];
int sub[N];
void dfs(int node){
	int big = 0;
	sub[node] = 1;
	for(int next : v[node]){
		dfs(next);
		sub[node] += sub[next];
		if(big == 0){
			big = next;
		}
		else if(s[next].size() > s[big].size()){
			big = next;
		}
	}
	s[node].clear();
	if(big){
		s[node].swap(s[big]);
	}
	for(int next : v[node]){
		if(next != big){
			s[node].insert(s[next].cbegin() , s[next].cend());
		}
	}
	s[node].insert(c[node]);
	dp[node][0][0] = 0;
	int cur = 0;
	for(int val : s[node]){
		++cur;
		dp[node][0][cur] = min(b + 1 , dp[node][0][cur - 1] + val);
	}
	for(int i = cur + 1 ; i <= n ; ++i){
		dp[node][0][i] = b + 1;
	}
	dp[node][1][0] = 0;
	dp[node][1][1] = c[node] - d[node];
	for(int i = 2 ; i <= n ; ++i){
		dp[node][1][i] = b + 1;
	}
	int mx = 1;
	for(int next : v[node]){
		int mn = sub[next];
		for(int j = mx ; j >= 1 ; --j){
			for(int k = 1 ; k <= mn ; ++k){
				dp[node][1][j + k] = min(dp[node][1][j + k] , dp[node][1][j] + dp[next][1][k]);
			}
		}
		mx += mn;
	}
	for(int i = 0 ; i <= n ; ++i){
		dp[node][1][i] = min(dp[node][1][i] , dp[node][0][i]);
	}
}
int main(){
	scanf("%d %d" , &n , &b);
	scanf("%d %d" , c + 1 , d + 1);
	par[1] = 0;
	for(int i = 2 ; i <= n ; ++i){
		scanf("%d %d %d" , c + i , d + i , par + i);
		v[par[i]].emplace_back(i);
	}
	dfs(1);
	for(int i = n ; i >= 0 ; --i){
		if(dp[1][1][i] <= b){
			printf("%d\n" , i);
			return 0;
		}
	}
}