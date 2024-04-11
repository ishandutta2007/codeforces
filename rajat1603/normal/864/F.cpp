#include "bits/stdc++.h"
using namespace std;
const int N = 3e3 + 3;
const int Q = 4e5 + 5;
int n , m , q;
int a , b;
vector < int > v[N];
vector < int > r[N];
int s[Q] , t[Q] , k[Q];
vector < int > ask[N];
int ans[Q];
vector < int > g[N];
int que[N];
int ql , qr;
bool visited[N];
vector < int > who[N];
void bfs1(int node){
	ql = qr = 0;
	memset(visited , 0 , sizeof(visited));
	que[qr++] = node;
	visited[node] = 1;
	while(ql < qr){
		int node = que[ql++];
		for(int next : r[node]){
			if(!visited[next]){
				visited[next] = 1;
				que[qr++] = next;
			}
		}
	}
}
int path[N];
int siz;
void dfs1(int node){
	path[++siz] = node;
	for(int i : who[node]){
		if(k[i] <= siz){
			ans[i] = path[siz - k[i] + 1];
		}
	}
	for(int next : g[node]){
		dfs1(next);
	}
	path[siz--] = 0;
}
void solve(int dest){
	bfs1(dest);
	for(int i = 1 ; i <= n ; ++i){
		g[i].clear();
	}
	for(int i = 1 ; i <= n ; ++i){
		if(i == dest){
			continue;
		}
		for(int j : v[i]){
			if(visited[j]){
				g[j].emplace_back(i);
				break;
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		who[i].clear();
	}
	for(int j : ask[dest]){
		who[s[j]].emplace_back(j);
	}
	siz = 0;
	dfs1(dest);
}
int main(){
	scanf("%d %d %d" , &n , &m , &q);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		r[b].emplace_back(a);
	}
	for(int i = 1 ; i <= n ; ++i){
		sort(v[i].begin() , v[i].end());
	}
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d %d" , s + i , t + i , k + i);
		ask[t[i]].emplace_back(i);
		ans[i] = -1;
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!ask[i].empty()){
			solve(i);
		}
	}
	for(int i = 1 ; i <= q ; ++i){
		printf("%d\n" , ans[i]);
	}
}