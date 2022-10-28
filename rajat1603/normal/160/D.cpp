#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
int a , b , c;
pair < pair < int , int > , pair < int , int > > arr[N];
int parent[N];
int tin[N];
int anc[N];
int ans[N];
vector < pair < int , int > > v[N];
int timer;
int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
void dfs(int node , int last){
	tin[node] = anc[node] = ++timer;
	for(auto it : v[node]){
		if(it.second == last){
			continue;
		}
		int next = it.first;
		if(!tin[next]){
			dfs(next , it.second);
			if(anc[next] > tin[node]){
				ans[it.second] = 0;
			}
			anc[node] = min(anc[node] , anc[next]);
		}
		else{
			anc[node] = min(anc[node] , tin[next]);
		}
	}
}
void solve(int l , int r){
	for(int i = l ; i <= r ; ++i){
		a = find(arr[i].second.first);
		b = find(arr[i].second.second);
		v[a].clear();
		v[b].clear();
		tin[a] = tin[b] = 0;
	}
	for(int i = l ; i <= r ; ++i){
		a = find(arr[i].second.first);
		b = find(arr[i].second.second);
		if(a == b){
			ans[arr[i].first.second] = 2;
		}
		else{
			ans[arr[i].first.second] = 1;
			v[a].emplace_back(make_pair(b , arr[i].first.second));
			v[b].emplace_back(make_pair(a , arr[i].first.second));
		}
	}
	timer = 0;
	for(int i = l ; i <= r ; ++i){
		a = find(arr[i].second.first);
		b = find(arr[i].second.second);
		if(!tin[a]){
			dfs(a , 0);
		}
	}
	for(int i = l ; i <= r ; ++i){
		a = find(arr[i].second.first);
		b = find(arr[i].second.second);
		parent[a] = b;
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , &a , &b , &c);
		arr[i] = {{c , i} , {a , b}};
	}
	sort(arr + 1 , arr + 1 + m);
	for(int i = 1 ; i <= n ; ++i){
		parent[i] = i;
	}
	for(int i = 1 ; i <= m ; ++i){
		int j = i;
		while(arr[j + 1].first.first == arr[j].first.first){
			++j;
		}
		solve(i , j);
		i = j;
	}
	for(int i = 1 ; i <= m ; ++i){
		printf("%s\n" , ans[i] ? ans[i] == 1 ? "at least one" : "none" : "any");
	}
}