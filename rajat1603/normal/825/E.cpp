#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
vector < int > v[N];
int a , b;
int indeg[N];
priority_queue < int > pq;
int ans[N];
int cur;
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , &a , &b);
		++indeg[a];
		v[b].emplace_back(a);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!indeg[i]){
			pq.push(i);
		}
	}
	cur = n;
	while(!pq.empty()){
		int node = pq.top();
		pq.pop();
		ans[node] = cur--;
		for(int next : v[node]){
			--indeg[next];
			if(!indeg[next]){
				pq.push(next);
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , ans[i] , " \n"[i == n]);
	}
}