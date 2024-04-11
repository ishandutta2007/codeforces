#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n , m , s;
int t[N] , a[N] , b[N];
vector < int > uni[N];
vector < int > bi[N];
int dir1[N];
int dir2[N];
bool visited[N];
int tot1;
int tot2;
void dfs1(int node){
	visited[node] = 1;
	++tot1;
	for(int next : uni[node]){
		if(!visited[next]){
			dfs1(next);
		}
	}
	for(int edge : bi[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(dir1[edge]){
			if(dir1[edge] == next){
				if(!visited[next]){
					dfs1(next);
				}
			}
			continue;
		}
		if(visited[next]){
			dir1[edge] = next;
			continue;
		}
		dir1[edge] = next;
		dfs1(next);
	}
}
void dfs2(int node){
	visited[node] = 1;
	++tot2;
	for(int next : uni[node]){
		if(!visited[next]){
			dfs2(next);
		}
	}
	for(int edge : bi[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(dir2[edge]){
			if(dir2[edge] == next){
				if(!visited[next]){
					dfs2(next);
				}
			}
			continue;
		}
		if(visited[next]){
			dir2[edge] = next;
			continue;
		}
		dir2[edge] = node;
	}
}
int main(){
	scanf("%d %d %d" , &n , &m , &s);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , &t[i] , &a[i] , &b[i]);
		if(t[i] == 1){
			uni[a[i]].emplace_back(b[i]);
		}
		else{
			bi[a[i]].emplace_back(i);
			bi[b[i]].emplace_back(i);
		}
	}
	memset(visited , 0 , sizeof(visited));
	dfs1(s);
	memset(visited , 0 , sizeof(visited));
	dfs2(s);
	printf("%d\n" , tot1);
	for(int i = 1 ; i <= m ; ++i){
		if(t[i] == 1){
			continue;
		}
		if(dir1[i] == 0 || dir1[i] == b[i]){
			printf("+");
		}
		else{
			printf("-");
		}
	}
	printf("\n");
	printf("%d\n" , tot2);
	for(int i = 1 ; i <= m ; ++i){
		if(t[i] == 1){
			continue;
		}
		if(dir2[i] == 0 || dir2[i] == b[i]){
			printf("+");
		}
		else{
			printf("-");
		}
	}
	printf("\n");
}