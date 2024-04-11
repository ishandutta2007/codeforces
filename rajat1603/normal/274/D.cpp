#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
pair < int , int > arr[N];
vector < int > v[N];
int indeg[N];
int ans[N];
int cur;
void addedge(int a , int b){
	v[a].emplace_back(b);
	++indeg[b];
}
void toposort(){
	int sz = 0;
	queue < int > q;
	for(int i = 1 ; i <= m ; ++i){
		if(!indeg[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		ans[++sz] = node;
		for(int next : v[node]){
			--indeg[next];
			if(!indeg[next]){
				q.push(next);
			}
		}
	}
	if(sz < cur){
		printf("-1\n");
	}
	else{
		for(int i = 1 ; i <= cur ; ++i){
			if(ans[i] <= m){
				printf("%d " , ans[i]);
			}
		}
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	cur = m;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			scanf("%d" , &arr[j].first);
			arr[j].second = j;
		}
		sort(arr + 1 , arr + 1 + m);
		for(int j = 1 ; j < m ; ++j){
			if(arr[j].first != -1){
				int idx = j;
				for(int k = j + 1 ; k <= m ; ++k){
					if(arr[k].first == arr[j].first){
						idx = k;
					}
					else{
						break;
					}
				}
				++cur;
				for(int k = j ; k <= idx ; ++k){
					addedge(arr[k].second , cur);
				}
				for(int k = idx + 1 ; k <= m ; ++k){
					if(arr[k].first == arr[idx + 1].first){
						addedge(cur , arr[k].second);
					}
				}
				j = idx;
			}
		}
	}
	toposort();
}