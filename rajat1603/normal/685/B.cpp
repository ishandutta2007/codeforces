#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n;
int par[N];
vector < int > v[N];
int subtree[N];
int inp;
int ans[N];
int nxt[N];
void dfs(int node){
	subtree[node] = 1;
	nxt[node] = node;
	int heavy = -1;
	int weight = 0;
	ans[node] = node;
	for(int next : v[node]){
		dfs(next);
		subtree[node] += subtree[next];
		if(subtree[next] > weight){
			weight = subtree[next];
			nxt[node] = next;
		}
	}
	int sz = subtree[node] >> 1;
	int tmp = ans[nxt[node]];
	bool rekt = 1;
	for(int next : v[node]){
		if(subtree[next] > sz){
			rekt = 0;
			break;
		}
	}
	if(rekt){
		ans[node] = node;
	}
	else{
		while(subtree[tmp] <= sz){
			tmp = par[tmp];
		}
		ans[node] = tmp;
	}
}
int q;
int main(){
	scanf("%d %d" , &n , &q);
	for(int i = 1 ; i <= n ; ++i){
		v[i].clear();
		nxt[i] = -1;
	}
	par[1] = 0;
	for(int i = 2 ; i <= n ; ++i){
		scanf("%d" , &inp);
		v[inp].emplace_back(i);
		par[i] = inp;
	}
	dfs(1);
	while(q--){
		scanf("%d" , &inp);
		printf("%d\n" , ans[inp]);
	}
}