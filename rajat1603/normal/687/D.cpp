#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int M = 5e5 + 5;
int n , m , q;
pair < pair < int , int > , pair < int , int > > edges[M];
int a , b , c;
int l , r;
int idx[M];
int cur;
vector < int > v[N];
int parent[N];
int col[N];
bool rekt;
int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
void merge(int a , int b){
	int x = find(a);
	int y = find(b);
	if(x != y){
		bool change = (col[a] == col[b]);
		if(v[x].size() < v[y].size()){
			for(int node : v[x]){
				v[y].emplace_back(node);
				col[node] ^= change;
			}
			v[x].clear();
			parent[x] = y;
		}
		else{
			for(int node : v[y]){
				v[x].emplace_back(node);
				col[node] ^= change;
			}
			v[y].clear();
			parent[y] = x;
		}
	}
	else{
		if(col[a] == col[b]){
			rekt = 1;
		}
	}
}
int main(){
	scanf("%d %d %d" , &n , &m , &q);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , &a , &b , &c);
		edges[i] = {{c , i} , {a , b}};
	}
	sort(edges + 1 , edges + 1 + m);
	reverse(edges + 1 , edges + 1 + m);
	while(q--){
		scanf("%d %d" , &l , &r);
		cur = 0;
		for(int i = 1 ; i <= m ; ++i){
			if(edges[i].first.second >= l && edges[i].first.second <= r){
				idx[++cur] = i;
			}
		}
		for(int i = 1 ; i <= n ; ++i){
			v[i].clear();
			parent[i] = i;
			col[i] = 0;
			v[i].emplace_back(i);
		}
		rekt = 0;
		for(int i = 1 ; i <= cur ; ++i){
			int a = edges[idx[i]].second.first;
			int b = edges[idx[i]].second.second;
			merge(a , b);
			if(rekt){
				printf("%d\n" , edges[idx[i]].first.first);
				break;
			}
		}
		if(!rekt){
			printf("-1\n");
		}
	}
}