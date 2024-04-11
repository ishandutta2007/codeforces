#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k;
char str[N];
int sz[N];
int nxt[N][26];
int cur = 1;
bool win[N];
bool lose[N];
void insert(){
	int node = 1;
	++sz[1];
	for(int i = 0 ; str[i] ; ++i){
		int c = str[i] - 'a';
		if(!nxt[node][c]){
			nxt[node][c] = ++cur;
		}
		node = nxt[node][c];
		++sz[node];
	}
}
void dfs(int node){
	bool leaf = 1;
	for(int i = 0 ; i < 26 ; ++i){
		if(nxt[node][i]){
			leaf = 0;
			dfs(nxt[node][i]);
		}
	}
	if(leaf){
		win[node] = 0;
		lose[node] = 1;
	}
	else{
		for(int i = 0 ; i < 26 ; ++i){
			if(nxt[node][i]){
				int next = nxt[node][i];
				if(!win[next]){
					win[node] = 1;
				}
				if(!lose[next]){
					lose[node] = 1;
				}
			}
		}
	}
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str);
		insert();
	}
	dfs(1);
	if(!win[1]){
		printf("Second\n");
	}
	else if(lose[1]){
		printf("First\n");
	}
	else{
		printf((k & 1) ? "First\n" : "Second\n");
	}
}