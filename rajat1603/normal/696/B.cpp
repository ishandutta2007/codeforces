#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int par;
vector < int > v[N];
int subtree[N];
double ans[N];
void predfs(int node){
	subtree[node] = 1;
	for(int next : v[node]){
		predfs(next);
		subtree[node] += subtree[next];
	}
}
void dfs(int node , double val){
	++val;
	ans[node] = val;
	int sum = 0;
	for(int next : v[node]){
		sum += subtree[next];
	}
	for(int next : v[node]){
		dfs(next , val + (1.0 * sum - subtree[next]) / 2.0);
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 2 ; i <= n ; ++i){
		scanf("%d" , &par);
		v[par].emplace_back(i);
	}
	predfs(1);
	dfs(1 , 0);
	for(int i = 1 ; i <= n ; ++i){
		printf("%.6lf%c" , ans[i] , " \n"[i == n]);
	}
}