#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
vector < int > v[N];
int visited[N];
int a , b;
vector < int > aa;
vector < int > bb;
void dfs(int node){
	if(visited[node]){
		aa.emplace_back(node);
	}
	else{
		bb.emplace_back(node);
	}
	for(int next : v[node]){
		if(visited[next] == -1){
			visited[next] = visited[node] ^ 1;
			dfs(next);
		}
		if(visited[next] == visited[node]){
			printf("-1\n");
			exit(0);
		}
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	memset(visited , -1 , sizeof(visited));
	for(int i = 1 ; i <= n ; ++i){
		if(visited[i] == -1){
			visited[i] = 0;
			dfs(i);
		}
	}
	printf("%d\n" , int(aa.size()));
	for(int x : aa){
		printf("%d " , x);
	}
	printf("\n%d\n" , int(bb.size()));
	for(int x : bb){
		printf("%d " , x);
	}
}