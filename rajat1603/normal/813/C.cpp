#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , x;
int a , b;
vector < int > v[N];
int dist1[N];
int dist2[N];
int ans;
void dfs(int node , int parent , int dist[]){
	dist[node] = dist[parent] + 1;
	for(int next : v[node]){
		if(next != parent){
			dfs(next , node , dist);
		}
	}
}
int main(){
	scanf("%d %d" , &n , &x);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dist1[0] = -1;
	dist2[0] = -1;
	dfs(1 , 0 , dist1);
	dfs(x , 0 , dist2);
	for(int i = 1 ; i <= n ; ++i){
		if(dist2[i] < dist1[i]){
			ans = max(ans , dist1[i] * 2);
		}
	}
	printf("%d\n" , ans);
}