#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , m;
int arr[N];
int l , r;
int parent[N];
int ans[N];
vector < int > idx[N];
vector < int > val[N];
int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		parent[i] = i;
	}
	while(m--){
		scanf("%d %d" , &l , &r);
		parent[find(l)] = find(r);
	}
	for(int i = 1 ; i <= n ; ++i){
		idx[find(i)].emplace_back(i);
		val[find(i)].emplace_back(arr[i]);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(find(i) == i){
			sort(val[i].begin() , val[i].end());
			int idxx = val[i].size() - 1;
			for(int id : idx[i]){
				ans[id] = val[i][idxx--];
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , ans[i] , " \n"[i == n]);
	}
}