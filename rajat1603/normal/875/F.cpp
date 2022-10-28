#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , m;
pair < int , pair < int , int > > arr[N];
int ans;
int parent[N];
int cycle[N];
int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
bool addedge(int a , int b){
	int x = find(a);
	int y = find(b);
	if(x != y){
		if(cycle[x] && cycle[y]){
			return 0;
		}
		parent[y] = x;
		cycle[x] |= cycle[y];
		return 1;
	}
	if(cycle[x]){
		return 0;
	}
	cycle[x] = 1;
	return 1;
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , &arr[i].second.first , &arr[i].second.second , &arr[i].first);
	}
	sort(arr + 1 , arr + 1 + m);
	for(int i = 1 ; i <= n ; ++i){
		parent[i] = i;
		cycle[i] = 0;
	}
	for(int i = m ; i >= 1 ; --i){
		ans += addedge(arr[i].second.first , arr[i].second.second) * arr[i].first;
	}
	printf("%d\n" , ans);
}