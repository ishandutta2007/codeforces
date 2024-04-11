#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n , m;
int a[N] , b[N] , c[N];
int parent[N];
int q;
int ans[N];
vector < int > edges[N];
vector < pair < int , int > > queries[N];
int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
int tmpparent[N];
int tmpfind(int node){
	if(tmpparent[node] == node){
		return node;
	}
	return tmpparent[node] = tmpfind(tmpparent[node]);
}
void solve(vector < pair < int , int > > &queries , int l , int r){
	if(ans[queries[l].first] == 0){
		return;
	}
	for(int i = l ; i <= r ; ++i){
		int idx = queries[i].second;
		int a = find(::a[idx]);
		int b = find(::b[idx]);
		if(a == b){
			ans[queries[l].first] = 0;
			return;
		}
		tmpparent[a] = a;
		tmpparent[b] = b;
	}
	for(int i = l ; i <= r ; ++i){
		int idx = queries[i].second;
		int a = find(::a[idx]);
		int b = find(::b[idx]);
		a = tmpfind(a);
		b = tmpfind(b);
		if(a == b){
			ans[queries[l].first] = 0;
			return;
		}
		tmpparent[b] = a;
	}
}
void solve(vector < pair < int , int > > &queries){
	if(queries.empty()){
		return;
	}
	sort(queries.begin() , queries.end());
	for(int i = 0 ; i < queries.size() ; ++i){
		int j = i;
		while(j + 1 < queries.size() && queries[j + 1].first == queries[j].first){
			++j;
		}
		solve(queries , i , j);
		i = j;
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , a + i , b + i , c + i);
		edges[c[i]].emplace_back(i);
	}
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; ++i){
		int siz , val;
		scanf("%d" , &siz);
		for(int j = 0 ; j < siz ; ++j){
			scanf("%d" , &val);
			queries[c[val]].emplace_back(make_pair(i , val));
		}
		ans[i] = 1;
	}
	for(int i = 1 ; i <= n ; ++i){
		parent[i] = i;
	}
	for(int i = 0 ; i < N ; ++i){
		solve(queries[i]);
		for(int idx : edges[i]){
			parent[find(b[idx])] = find(a[idx]);
		}
	}
	for(int i = 1 ; i <= q ; ++i){
		printf(ans[i] ? "YES\n" : "NO\n");
	}
}