#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const long long inf = 1e18 + 18;
int n;
long long start[N];
long long finish[N];
int parent[N];
long long k[N];
vector < int > v[N];
int depth[N];
vector < int > levels[N];
void dfs(int node){
	for(int next : v[node]){
		depth[next] = depth[node] + 1;
		dfs(next);
	}
}
long long mult(long long a , long long b){
	if(a >= inf / b + 2){
		return inf;
	}
	return min(a * b , inf);
}
void solve(int node){
	if(start[node] == finish[node]){
		return;
	}
	if(start[node] < finish[node]){
		long long need = finish[node] - start[node];
		long long take = mult(need , k[node]);
		if(take >= inf){
			printf("NO\n");
			exit(0);
		}
		start[parent[node]] -= take;
		if(start[parent[node]] <= -inf){
			printf("NO\n");
			exit(0);
		}
		start[node] = finish[node];
		return;	
	}
	if(start[node] > finish[node]){
		long long give = start[node] - finish[node];
		start[parent[node]] += give;
		start[node] = finish[node];
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld" , start + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld" , finish + i);
	}
	for(int i = 2 ; i <= n ; ++i){
		scanf("%d %lld" , parent + i , k + i);
		v[parent[i]].emplace_back(i);
	}
	depth[1] = 1;
	dfs(1);
	for(int i = 1 ; i <= n ; ++i){
		levels[depth[i]].emplace_back(i);
	}
	for(int i = n ; i > 1 ; --i){
		for(int node : levels[i]){
			solve(node);
		}
	}
	if(start[1] >= finish[1]){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}