#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , m;
int a , b , c;
vector < pair < int , int > > v[N];
int comp[N];
vector < int > v2[N];
int compno;
vector < int > g[N];
vector < int > ans;
int color[N];
void dfs(int node){
	if(comp[node]){
		return;
	}
	comp[node] = compno;
	v2[comp[node]].emplace_back(node);
	for(auto next : v[node]){
		if(next.second){
			dfs(next.first);
		}
	}
}
void dfs2(int node){
	if(color[node]){
		for(int x : v2[node]){
			ans.emplace_back(x);
		}
	}
	for(int next : g[node]){
		if(color[next] == -1){
			color[next] = color[node] ^ 1;
			dfs2(next);
		}
		if(color[next] == color[node]){
			printf("Impossible\n");
			exit(0);
		}
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , &a , &b , &c);
		v[a].emplace_back(make_pair(b , c));
		v[b].emplace_back(make_pair(a , c));
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!comp[i]){
			++compno;
			dfs(i);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(auto it : v[i]){
			if(!it.second){
				g[comp[i]].emplace_back(comp[it.first]);
			}
		}
	}
	memset(color , -1 , sizeof(color));
	for(int i = 1 ; i <= compno ; ++i){
		if(color[i] == -1){
			color[i] = 0;
			dfs2(i);
		}
	}
	printf("%d\n" , int(ans.size()));
	for(int x : ans){
		printf("%d " , x);
	}
}