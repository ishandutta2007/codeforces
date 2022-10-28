#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n , m;
vector < int > s[N];
vector < int > v[N];
int col[N];
int mark[N];
void dfs(int node , int parent){
	for(int x : s[node]){
		mark[col[x]] = node;
	}
	int cur = 1;
	for(int x : s[node]){
		if(!col[x]){
			while(mark[cur] == node){
				++cur;
			}
			col[x] = cur;
			mark[cur] = node;
		}
	}
	for(int next : v[node]){
		if(next != parent){
			dfs(next , node);
		}
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		int siz;
		scanf("%d" , &siz);
		s[i].clear();
		s[i].resize(siz);
		for(int j = 0 ; j < siz ; ++j){
			scanf("%d" , &s[i][j]);
		}
	}
	for(int i = 1 ; i < n ; ++i){
		int a , b;
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dfs(1 , 0);
	for(int i = 1 ; i <= m ; ++i){
		if(col[i] == 0){
			col[i] = 1;
		}
	}
	printf("%d\n" , *max_element(col + 1 , col + 1 + m));
	for(int i = 1 ; i <= m ; ++i){
		printf("%d%c" , col[i] , " \n"[i == m]);
	}
}