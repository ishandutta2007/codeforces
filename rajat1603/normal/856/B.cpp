#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int t;
int n;
char str[N];
int child[N][26];
int cur;
void insert(){
	int node = 1;
	for(int i = 0 ; str[i] ; ++i){
		int c = str[i] - 'a';
		if(!child[node][c]){
			child[node][c] = ++cur;
		}
		node = child[node][c];
	}
}
int lcs[N];
int que[N];
int dep[N];
int ql , qr;
inline int find(int node , int c){
	if(child[node][c]){
		return child[node][c];
	}
	if(node == 1){
		return 1;
	}
	return find(lcs[node] , c);
}
void bfs(){
	ql = 0;
	qr = 0;
	lcs[1] = 1;
	dep[1] = 0;
	que[qr++] = 1;
	while(ql < qr){
		int node = que[ql++];
		for(int i = 0 ; i < 26 ; ++i){
			if(!child[node][i]){
				continue;
			}
			int next = child[node][i];
			if(node == 1){
				lcs[next] = node;
			}
			else{
				lcs[next] = find(lcs[node] , i);
			}
			dep[next] = dep[node] + 1;
			que[qr++] = next;
		}
	}
}
vector < int > v[N];
int visited[N];
int tc;
int ans;
int dp[N][2];
void dfs(int node){
	visited[node] = tc;
	dp[node][1] = 1;
	dp[node][0] = 0;
	for(int next : v[node]){
		if(visited[next] == tc){
			continue;
		}
		dfs(next);
		dp[node][0] += dp[next][1];
		dp[node][1] += dp[next][0];
	}
	dp[node][1] = max(dp[node][1] , dp[node][0]);
}
int main(){
	scanf("%d" , &t);
	while(t--){
		scanf("%d" , &n);
		for(int i = 1 ; i <= cur ; ++i){
			memset(child[i] , 0 , sizeof(child[i]));
		}
		cur = 1;
		for(int i = 1 ; i <= n ; ++i){
			scanf("%s" , str);
			insert();
		}
		bfs();
		for(int i = 1 ; i <= cur ; ++i){
			v[i].clear();
		}
		for(int i = 2 ; i <= cur ; ++i){
			if(dep[lcs[i]] + 1 == dep[i] && lcs[i] != 1){
				v[lcs[i]].emplace_back(i);
				v[i].emplace_back(lcs[i]);
			}
		}
		++tc;
		ans = 0;
		for(int i = 2 ; i <= cur ; ++i){
			if(visited[i] != tc){
				dfs(i);
				ans += dp[i][1];
			}
		}
		printf("%d\n" , ans);
	}
}