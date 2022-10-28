#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
vector < int > v[N];
int a , b;
int ans;
bool visited[N];
bool rekt;
void dfs(int node , int last){
	visited[node] = 1;
	for(int next : v[node]){
		if(next == last){
			continue;
		}
		if(!visited[next]){
			dfs(next , node);
		}
		else{
			rekt = 1;
		}
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!visited[i]){
			rekt = 0;
			dfs(i , 0);
			ans += !rekt;
		}
	}
	cout << ans;
}