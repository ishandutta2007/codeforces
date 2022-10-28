#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n , m , k;
int rnk[N];
int arr[N];
int low[N];
vector < int > v[N];
vector < int > rv[N];
vector < int > topo;
int indeg[N];
void toposort(){
	memset(indeg , 0 , sizeof(indeg));
	for(int i = 1 ; i <= n ; ++i){
		for(int x : v[i]){
			++indeg[x];
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!indeg[i]){
			v[0].emplace_back(i);
			rv[i].emplace_back(0);
			++indeg[i];
		}
	}
	topo.clear();
	queue < int > que;
	while(!que.empty()){
		que.pop();
	}
	que.push(0);
	while(!que.empty()){
		int node = que.front();
		topo.emplace_back(node);
		que.pop();
		for(int next : v[node]){
			--indeg[next];
			if(!indeg[next]){
				que.push(next);
			}
		}
	}
}
vector < int > there[N];
set < int > s;
int main(){
	scanf("%d %d %d" , &n , &m , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , rnk + i);
	}
	for(int i = 1 ; i <= m ; ++i){
		int a , b;
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		rv[b].emplace_back(a);
	}
	++k;
	rnk[0] = k;
	toposort();
	if(topo.size() != n + 1){
		printf("-1\n");
		return 0;
	}
	for(int i = n ; i >= 0 ; --i){
		int node = topo[i];
		low[node] = 1;
		for(int next : v[node]){
			low[node] = max(low[node] , low[next] + 1);
		}
		if(rnk[node] != 0){
			if(rnk[node] < low[node]){
				printf("-1\n");
				return 0;
			}
			low[node] = rnk[node];
		}
		arr[node] = low[node];
		there[arr[node]].emplace_back(node);
		if(arr[node] > k){
			printf("-1\n");
			return 0;
		}
	}
	for(int i = k ; i >= 1 ; --i){
		s.insert(i);
	}
	for(int i = 0 ; i <= n ; ++i){
		s.erase(arr[i]);
	}
	for(int i = k ; i >= 1 ; --i){
		vector < pair < int , int > > g;
		g.clear();
		for(int x : there[i]){
			int val = k;
			for(int y : rv[x]){
				val = min(val , arr[y] - 1);
			}
			if(rnk[x] != 0){
				val = rnk[x];
			}
			g.emplace_back(make_pair(val , x));
		}
		s.insert(i);
		sort(g.begin() , g.end());
		reverse(g.begin() , g.end());
		for(auto itt : g){
			int node = itt.second;
			int high = itt.first;
			if(low[node] > high){
				printf("-1\n");
			}
			auto it = s.lower_bound(high + 1);
			int val = -1;
			if(it != s.begin()){
				--it;
				val = *it;
			}
			if(val >= low[node]){
				arr[node] = val;
			}
			else{
				arr[node] = high;
			}
			s.erase(arr[node]);
		}
	}
	if(!s.empty()){
		printf("-1\n");
		return 0;
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , arr[i] , " \n"[i == n]);
	}
}