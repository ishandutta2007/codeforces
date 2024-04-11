#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int a , b;
vector < int > v[N];
int depth[N];
double ans;
void dfs(int node , int parent){
	depth[node] = depth[parent] + 1;
	for(int next : v[node]){
		if(next != parent){
			dfs(next , node);
		}
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dfs(1 , 0);
	for(int i = 1 ; i <= n ; ++i){
		ans += 1.0 / depth[i];
	}
	printf("%.9lf\n" , ans);
}