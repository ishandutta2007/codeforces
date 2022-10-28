#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
vector < int > v[N];
int comp[N];
int cur;
vector < int > change;
void dfs(int node , int last){
	comp[node] = cur;
	for(int edge : v[node]){
		if(edge == last){
			continue;
		}
		int next = edge ^ arr[edge] ^ node;
		if(comp[next] == 0){
			dfs(next , edge);
		}
		else{
			change.emplace_back(edge);
		}
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		v[i].emplace_back(i);
		v[arr[i]].emplace_back(i);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!comp[i]){
			++cur;
			dfs(i , 0);
		}
	}
	if(cur == 1){
		int cnt = 0;
		for(int i = 1 ; i <= n ; ++i){
			if(arr[i] == i){
				++cnt;
			}
		}
		if(cnt == 1){
			printf("0\n");
			for(int i = 1 ; i <= n ; ++i){
				printf("%d%c" , arr[i] , " \n"[i == n]);
			}
			return 0;
		}
		arr[change[0]] = change[0];
		printf("1\n");
		for(int i = 1 ; i <= n ; ++i){
			printf("%d%c" , arr[i] , " \n"[i == n]);
		}
		return 0;
	}
	sort(change.begin() , change.end());
	change.resize(unique(change.begin() , change.end()) - change.begin());
	int root = -1;
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] == i){
			root = i;
			break;
		}
	}
	int ans = 0;
	for(auto it : change){
		if(it != root){
			arr[it] = root;
			++ans;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] == -1){
			if(root == -1){
				root = i;
			}
			arr[i] = root;
		}
	}
	printf("%d\n" , ans);
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , arr[i] , " \n"[i == n]);
	}
}