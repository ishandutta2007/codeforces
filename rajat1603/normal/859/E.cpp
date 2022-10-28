#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n;
int a[N] , b[N];
vector < int > v[N];
bool visited[N];
vector < int > tmp;
bool cycle;
int parent[N];
bool self;
void dfs1(int node , int parent){
	tmp.emplace_back(node);
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(edge != parent){
			if(visited[next]){
				cycle = 1;
				if(next == node){
					self = 1;
				}
			}
			else{
				visited[next] = 1;
				dfs1(next , edge);
			}
		}
	}
}
int dp[N];
void dfs2(int node , int parent){
	dp[node] = 1;
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(next != parent){
			dfs2(next , node);
			dp[node] += dp[next];
			dp[node] %= mod;
		}
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , &a[i] , &b[i]);
		v[b[i]].emplace_back(i);
		v[a[i]].emplace_back(i);
		parent[a[i]] = b[i];
	}
	int tot = 1;
	for(int i = 1 ; i <= n + n ; ++i){
		if(visited[i]){
			continue;
		}
		visited[i] = 1;
		cycle = 0;
		self = 0;
		tmp.clear();
		dfs1(i , 0);
		int ans;
		if(cycle){
			ans = 2;
			if(self){
				ans = 1;
			}
		}
		else{
			int root;
			for(int x : tmp){
				if(!parent[x]){
					root = x;
				}
			}
			dfs2(root , 0);
			ans = dp[root];
		}
		tot = (1LL * tot * ans) % mod;
	}
	printf("%d\n" , tot);
}