#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
vector < pair < int , int > > v[N];
int a , b;
vector < int > ans[N];
int mx;
void dfs(int node , int parent , int time){
	int cur = 0;
	for(auto it : v[node]){
		int next = it.first;
		if(next != parent){
			++cur;
			cur += (cur == time);
			ans[cur].emplace_back(it.second);
			mx = max(mx , cur);
			dfs(next , node , cur);
		}
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(make_pair(b , i));
		v[b].emplace_back(make_pair(a , i));
	}
	dfs(1 , 0 , 0);
	printf("%d" , mx);
	for(int i = 1 ; i <= mx ; ++i){
		printf("\n%d " , ans[i].size());
		for(int edge : ans[i]){
			printf("%d " , edge);
		}
	}
}