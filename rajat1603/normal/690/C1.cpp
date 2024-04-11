#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n , m;
int parent[N];
int tot;
int a , b;
int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
bool join(int a , int b){
	if(find(a) == find(b)){
		return 0;
	}
	parent[find(a)] = find(b);
	return 1;
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		parent[i] = i;
	}
	tot = 0;
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , &a , &b);
		if(!join(a , b)){
			printf("no\n");
			return 0;
		}
		++tot;
	}
	if(tot == n - 1){
		printf("yes\n");
	}
	else{
		printf("no\n");
	}
}