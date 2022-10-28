#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
int n;
int a , b;
vector < int > v[N];
int ans;
void dfs(int node , int parent){
	int childcnt = 0;
	int parcnt = 0;
	for(int next : v[node]){
		if(next != parent){
			dfs(next , node);
			++childcnt;
		}
		else{
			++parcnt;
		}
	}
	ans += childcnt * (childcnt - 1) / 2;
	ans += parcnt * childcnt;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dfs(1 , 0);
	printf("%d\n" , ans);
}