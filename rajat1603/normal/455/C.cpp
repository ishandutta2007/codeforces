#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n , m , q;
vector < int > v[N];
int dia[N];
int parent[N];
int type , a , b;
int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
pair < int , int > dfs(int node , int baap){
	int ret1 = 0;
	int ret2 = 0;
	int ret3 = 0;
	for(int next : v[node]){
		if(next != baap){
			auto it = dfs(next , node);
			ret3 = max(ret3 , it.second);
			if(it.first + 1 > ret1){
				ret2 = ret1;
				ret1 = it.first + 1;
			}
			else if(it.first + 1 > ret2){
				ret2 = it.first + 1;
			}
		}
	}
	ret3 = max(ret3 , ret1 + ret2);
	return make_pair(ret1 , ret3);
}
int main(){
	scanf("%d %d %d" , &n , &m , &q);
	for(int i = 1 ; i <= n ; ++i){
		parent[i] = i;
	}
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
		parent[find(b)] = find(a);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(find(i) == i){
			dia[i] = dfs(i , 0).second;
		}
	}
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d" , &type , &a);
		if(type == 1){
			printf("%d\n" , dia[find(a)]);
		}
		else{
			scanf("%d" , &b);
			int x = find(a);
			int y = find(b);
			if(x != y){
				parent[y] = x;
				dia[x] = max(((dia[x] + 1) >> 1) + 1 + ((dia[y] + 1) >> 1) , max(dia[x] , dia[y]));
			}
		}
	}
}