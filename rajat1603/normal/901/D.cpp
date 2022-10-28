#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
long long arr[N];
int a[N] , b[N];
vector < int > v[N];
long long ans[N];
bool visited[N];
vector < int > cycle;
int parent[N];
int depth[N];
void dfs(int node){
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(visited[next]){
			continue;
		}
		visited[next] = 1;
		parent[next] = edge;
		depth[next] = depth[node] + 1;
		dfs(next);
	}
}
void dfs2(int node){
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(visited[next]){
			continue;
		}
		visited[next] = 1;
		dfs2(next);
		ans[edge] += arr[next];
		arr[next] -= ans[edge];
		arr[node] -= ans[edge];
	}
}
vector < int > x , y;
void get(int a , int b , int i){
	int aa = a;
	while(a != b){
		if(depth[a] > depth[b]){
			int edge = parent[a];
			x.emplace_back(edge);
			a = ::a[edge] ^ ::b[edge] ^ a;
		}
		else{
			int edge = parent[b];
			y.emplace_back(edge);
			b = ::a[edge] ^ ::b[edge] ^ b;	
		}
	}
	reverse(y.begin() , y.end());
	memset(visited , 0 , sizeof(visited));
	visited[aa] = 1;
	dfs2(aa);
	long long add = arr[aa] / 2;
	for(int edge : x){
		ans[edge] += add;
		add *= -1;
	}
	for(int edge : y){
		ans[edge] += add;
		add *= -1;
	}
	ans[i] += add;
	add *= -1;
	arr[aa] = 0;
}
void fix(){
	for(int i = 1 ; i <= m ; ++i){
		if(parent[a[i]] == b[i] || parent[b[i]] == a[i]){
			continue;
		}
		if((depth[a[i]] & 1) == (depth[b[i]] & 1)){
			get(a[i] , b[i] , i);
			return;
		}
		else{
			continue;
		}
	}
	memset(visited , 0 , sizeof(visited));
	visited[1] = 1;
	dfs2(1);
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld" , arr + i);
	}
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , a + i , b + i);
		v[a[i]].emplace_back(i);
		v[b[i]].emplace_back(i);
	}
	visited[1] = 1;
	dfs(1);
	fix();
	if(arr[1]){
		printf("NO\n");
	}
	else{
		printf("YES\n");
		for(int i = 1 ; i <= m ; ++i){
			printf("%lld\n" , ans[i]);
		}
	}
}