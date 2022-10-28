#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
const int V = 3e4 + 4;
const int inf = 1e6 + 6;
int n , m , k;
int x[N] , y[N];
int arr[N];
vector < pair < int , int > > v[V];
int dist[V];
queue < int > q;
int ans;
bool adjacent(int a , int b){
	return abs(x[a] - x[b]) + abs(y[a] - y[b]) == 1;
}
int main(){
	scanf("%d %d %d" , &n , &m , &k);
	for(int i = 1 ; i <= k ; ++i){
		scanf("%d %d" , x + i , y + i);
		arr[i] = i;
	}
	sort(arr + 1 , arr + 1 + k , [](int a , int b){
		if(x[a] == x[b]){
			return y[a] < y[b];
		}
		return x[a] < x[b];
	});
	for(int i = 1 ; i < k ; ++i){
		if(adjacent(arr[i] , arr[i + 1])){
			v[arr[i]].push_back({arr[i + 1] , 0});
			v[arr[i + 1]].push_back({arr[i] , 0});
		}
	}
	sort(arr + 1 , arr + 1 + k , [](int a , int b){
		if(y[a] == y[b]){
			return x[a] < x[b];
		}
		return y[a] < y[b];
	});
	for(int i = 1 ; i < k ; ++i){
		if(adjacent(arr[i] , arr[i + 1])){
			v[arr[i]].push_back({arr[i + 1] , 0});
			v[arr[i + 1]].push_back({arr[i] , 0});
		}
	}
	for(int i = 1 ; i <= k ; ++i){
		v[i].push_back({x[i] + k , 1});
		v[x[i] + k].push_back({i , 0});
		if(x[i] < n){
			v[i].push_back({x[i] + k + 1 , 1});
			v[x[i] + k + 1].push_back({i , 0});
		}
		if(x[i] > 1){
			v[i].push_back({x[i] + k - 1 , 1});
			v[x[i] + k - 1].push_back({i , 0});
		}
		v[i].push_back({y[i] + k + n , 1});
		v[y[i] + k + n].push_back({i , 0});
		if(y[i] < m){
			v[i].push_back({y[i] + k + n + 1 , 1});
			v[y[i] + k + n + 1].push_back({i , 0});
		}
		if(y[i] > 1){
			v[i].push_back({y[i] + k + n - 1 , 1});
			v[y[i] + k + n - 1].push_back({i , 0});
		}
	}
	for(int i = 1 ; i <= n + m + k ; ++i){
		dist[i] = inf;
	}
	for(int i = 1 ; i <= k ; ++i){
		if(make_pair(x[i] , y[i]) == make_pair(1 , 1)){
			dist[i] = 0;
			q.push(i);
		}
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto it : v[node]){
			int next = it.first;
			if(dist[next] > dist[node] + it.second){
				dist[next] = dist[node] + it.second;
				q.push({next});
			}
		}
	}
	ans = min(dist[k + n] , dist[k + n + m]);
	for(int i = 1 ; i <= k ; ++i){
		if(x[i] == n){
			ans = min(ans , dist[i] + 1);
		}
		if(y[i] == m){
			ans = min(ans , dist[i] + 1);
		}
		if(x[i] == n && y[i] == m){
			ans = min(ans , dist[i]);
		}
	}
	if(ans == inf){
		ans = -1;
	}
	printf("%d\n" , ans);
}