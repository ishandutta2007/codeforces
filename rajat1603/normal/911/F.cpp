#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int a , b;
vector < int > v[N];
int dist1[N];
int parent1[N];
int dist2[N];
int parent2[N];
int who , far;
long long ans;
void dfs(int node , int parent , int level , int dist[] , int par[]){
	dist[node] = level;
	par[node] = parent;
	if(level > far){
		far = level;
		who = node;
	}
	for(int next : v[node]){
		if(next != parent){
			dfs(next , node , level + 1 , dist , par);
		}
	}
}
void go(int node , int parent){
	for(int next : v[node]){
		if(next == parent){
			continue;
		}
		if(dist1[next] + dist2[next] > dist1[b]){
			go(next , node);
			if(dist1[next] > dist2[next]){
				printf("%d %d %d\n" , a , next , next);
			}
			else{
				printf("%d %d %d\n" , b , next , next);
			}
		}
	}
	for(int next : v[node]){
		if(next == parent){
			continue;
		}
		if(dist1[next] + dist2[next] == dist1[b]){
			go(next , node);
			printf("%d %d %d\n" , a , next , next);
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
	far = 0;
	dfs(1 , 0 , 0 , dist1 , parent1);
	a = who;
	far = 0;
	dfs(a , 0 , 0 , dist1 , parent1);
	b = who;
	far = 0;
	dfs(b , 0 , 0 , dist2 , parent2);
	for(int i = 1 ; i <= n ; ++i){
		if(dist1[i] + dist2[i] > dist1[b]){
			ans += max(dist1[i] , dist2[i]);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(dist1[i] + dist2[i] == dist1[b]){
			ans += dist1[i];
		}
	}
	printf("%lld\n" , ans);
	go(a , 0);
}