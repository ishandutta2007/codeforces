#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n , q;
int arr[N];
int a[N] , b[N];
vector < int > v[N];
int ans[N];
int dsu[N];
int find(int node){
	if(dsu[node] == node){
		return node;
	}
	return dsu[node] = find(dsu[node]);
}
int dfs(int node , int last){
	int res = arr[node];
	if(res == -1){
		res = 0;
	}
	for(int edge : v[node]){
		if(edge != last){
			int next = node ^ a[edge] ^ b[edge];
			int ret = dfs(next , edge);
			res ^= ret;
			if(ret){
				ans[edge] ^= 1;
			}
		}
	}
	return res;
}
int main(){
	scanf("%d %d" , &n , &q);
	int there = 0;
	bool odd = 0;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		if(arr[i] == -1){
			there = i;
		}
		else if((arr[i] & 1)){
			odd ^= 1;
		}
	}
	if(odd){
		if(there){
			arr[there] = 1;
		}
		else{
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		dsu[i] = i;
	}
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d" , a + i , b + i);
	}
	for(int i = 1 ; i <= q ; ++i){
		ans[i] = 0;
		if(find(a[i]) != find(b[i])){
			dsu[find(a[i])] = find(b[i]);
			v[a[i]].emplace_back(i);
			v[b[i]].emplace_back(i);
		}
	}
	dfs(1 , 0);
	vector < int > print;
	print.clear();
	for(int i = 1 ; i <= q ; ++i){
		if(ans[i]){
			print.emplace_back(i);
		}
	}
	printf("%d\n" , int(print.size()));
	for(int x : print){
		printf("%d\n" , x);
	}
}