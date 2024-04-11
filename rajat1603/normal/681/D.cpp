#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
vector < int > v[N];
vector < int > ans;
int arr[N];
bool visited1[N];
bool visited2[N];
int pos[N];
int indeg[N];
int a , b;
void dfs(int node){
	visited1[node] = 1;
	visited2[arr[node]] = 1;
	for(int next : v[node]){
		dfs(next);
	}
	if(visited2[node]){
		ans.emplace_back(node);
	}
}
void rekt(){
	printf("-1\n");
	exit(0);
}
multiset < int > ms;
void dfs2(int node){
	visited1[node] = 1;
	if(pos[node] != -1){
		ms.insert(pos[node]);
	}
	if(ms.empty()){
		rekt();
	}
	int val = *ms.begin();
	if(ans[val] != arr[node]){
		rekt();
	}
	for(int next : v[node]){
		dfs2(next);
	}
	if(pos[node] != -1){
		ms.erase(ms.find(pos[node]));
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	while(m--){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		++indeg[b];
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &arr[i]);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!visited1[i] && !indeg[i]){
			dfs(i);
		}
	}
	memset(pos , -1 , sizeof(pos));
	for(int i = 0 ; i < ans.size() ; ++i){
		pos[ans[i]] = i;
	}
	memset(visited1 , 0 , sizeof(visited1));
	for(int i = 1; i <= n; i++){
		if(!visited1[i] && !indeg[i]){
			dfs2(i);
		}
	}
 	printf("%d\n" , int(ans.size()));
 	for(int node : ans){
 		printf("%d\n" , node);
 	}
}