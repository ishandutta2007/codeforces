#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int t;
int n , k;
int depth[N];
int parent[N];
vector < int > v[N];
int visited[N];
vector < pair < int , int > > arr;
void dfs(int node , int l){
	visited[node] = l;
	for(int next : v[node]){
		if(visited[next] != l){
			dfs(next , l);
		}
	}
}
void fix(int node , int dist){
	int root = node;
	for(int i = 1 ; i < dist ; ++i){
		root = parent[root];
	}
	dfs(root , dist);
}
bool check(int l){
	int cnt = 0;
	for(auto it : arr){
		if(it.first <= l){
			break;
		}
		int node = it.second;
		if(visited[node] != l){
			++cnt;
			fix(node , l);
		}
		if(cnt > k){
			break;
		}
	}
	return cnt <= k;
}
int main(){
	scanf("%d" , &t);
	while(t--){
		scanf("%d %d" , &n , &k);
		for(int i = 1 ; i <= n ; ++i){
			v[i].clear();
			visited[i] = 0;
		}
		arr.clear();
		arr.push_back({0 , 1});
		for(int i = 2 ; i <= n ; ++i){
			scanf("%d" , parent + i);
			depth[i] = depth[parent[i]] + 1;
			v[parent[i]].push_back(i);
			arr.push_back({depth[i] , i});
		}
		sort(arr.begin() , arr.end());
		reverse(arr.begin() , arr.end());
		int l = 1;
		int r = n - 1;
		while(l < r){
			int mid = l + r >> 1;
			if(check(mid)){
				r = mid;
			}
			else{
				l = mid + 1;
			}
		}
		printf("%d\n" , l);
	}
}