#include "bits/stdc++.h"
using namespace std;
const int N = 50;
const int magic = 1e3 + 3;
int n;
char str[N][N];
int parent[N];
int name[N];
vector < int > v[N];
int cur;
int siz[N];
int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
void join(int a , int b){
	if(find(a) == find(b)){
		return;
	}
	siz[find(a)] += siz[find(b)];
	parent[find(b)] = find(a);
}
int col[N];
int perm[N];
int colour(){
	if(!cur){
		return 0;
	}
	srand(clock());
	int ans = cur;
	for(int i = 1 ; i <= cur ; ++i){
		perm[i] = i;
	}
	for(int i = 0 ; i < magic ; ++i){
		memset(col , 0 , sizeof(col));
		int res = 0;
		for(int i = 1 ; i <= n ; ++i){
			int node = perm[i];
			int mask = 0;
			for(int prev : v[node]){
				mask |= 1 << col[prev];
			}
			for(int i = 1 ; ; ++i){
				if(!((mask >> i) & 1)){
					col[node] = i;
					break;
				}
			}
			res = max(res , col[node]);
		}
		ans = min(ans , res);
		random_shuffle(perm + 1 , perm + 1 + cur);
	}
	return ans;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		parent[i] = i;
		siz[i] = 1;
	}
	cur = 0;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str[i] + 1);
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(str[i][j] == 'A'){
				join(i , j);
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(parent[i] == i && siz[i] > 1){
			name[i] = ++cur;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(str[i][j] == 'X'){
				int x = find(i);
				int y = find(j);
				if(x == y){
					printf("-1\n");
					return 0;
				}
				x = name[x];
				y = name[y];
				if(x && y){
					v[x].emplace_back(y);
					v[y].emplace_back(x);
				}
			}
		}
	}
	printf("%d\n" , n + colour() - 1);
}