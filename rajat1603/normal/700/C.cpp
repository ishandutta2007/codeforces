#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int M = 3e4 + 4;
const int inf = 2e9 + 9;
int n , m;
int s , t;
int a[M];
int b[M];
int c[M];
vector < int > v[N];
int tin[N];
int low[N];
int pre[N];
int timer;
int ans;
int e1 , e2;
vector < int > edges;
int notallowed;
void checkans(int val , int edge1 , int edge2){
	if(val < ans){
		ans = val;
		e1 = edge1;
		e2 = edge2;
	}
}
void dfs(int node , int last){
	tin[node] = low[node] = ++timer;
	pre[node] = last;
	for(int edge : v[node]){
		if(edge != last && edge != notallowed){
			int next = a[edge] ^ b[edge] ^ node;
			if(!tin[next]){
				dfs(next , edge);
				low[node] = min(low[node] , low[next]);
			}
			else{
				low[node] = min(low[node] , tin[next]);
			}
		}
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	scanf("%d %d" , &s , &t);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , a + i , b + i , c + i);
		v[a[i]].emplace_back(i);
		v[b[i]].emplace_back(i);
	}
	ans = inf;
	e1 = -1;
	e2 = -1;
	dfs(s , 0);
	if(!tin[t]){
		checkans(0 , -1 , -1);
	}
	else{
		int node = t;
		while(node != s){
			int edge = pre[node];
			int par = a[edge] ^ b[edge] ^ node;
			if(low[node] > tin[par]){
				checkans(c[edge] , edge , -1);
			}
			else{
				edges.emplace_back(edge);
			}
			node = par;
		}
		for(int edge : edges){
			memset(tin , 0 , sizeof(tin));
			timer = 0;
			notallowed = edge;
			dfs(s , 0);
			int node = t;
			while(node != s){
				int edge = pre[node];
				int par = a[edge] ^ b[edge] ^ node;
				if(low[node] > tin[par]){
					checkans(c[notallowed] + c[edge] , notallowed , edge);
				}
				node = par;
			}
		}
	}
	if(ans >= inf){
		printf("-1\n");
		return 0;
	}
	printf("%d\n" , ans);
	printf("%d\n" , (e1 != -1) + (e2 != -1));
	if(e1 > 0){
		printf("%d " , e1);
	}
	if(e2 > 0){
		printf("%d " , e2);
	}
	printf("\n");
}