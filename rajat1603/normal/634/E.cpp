#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , k;
int arr[N];
int a , b;
vector < int > v[N];
int tmp[N];
int subtree1[N];
int subtree2[N];
int sum[N];
int bst1[N];
int bst2[N];
bool ret;
void dfs(int node , int parent){
	subtree1[node] = 1;
	subtree2[node] = tmp[node];
	for(int next : v[node]){
		if(next != parent){
			dfs(next , node);
			subtree1[node] += subtree1[next];
			subtree2[node] += subtree2[next];
		}
	}
}
void dfs1(int node , int parent){
	sum[node] = 0;
	bst1[node] = 0;
	bst2[node] = 0;
	for(int next : v[node]){
		if(next != parent){
			dfs1(next , node);
			if(subtree2[next] == subtree1[next]){
				sum[node] += subtree1[next];
			}
			else{
				if(sum[next] > bst1[node]){
					bst2[node] = bst1[node];
					bst1[node] = sum[next];
				}
				else if(sum[next] > bst2[node]){
					bst2[node] = sum[next];
				}
			}
		}
	}
	if(tmp[node]){
		++sum[node];
		sum[node] += bst1[node];
	}
	else{
		sum[node] = 0;
		bst1[node] = 0;
		bst2[node] = 0;
	}
	ret |= (sum[node] >= k);
}
void dfs2(int node , int parent , int val){
	if(val == n - subtree1[node]){
		sum[node] += val;
	}
	else{
		sum[node] -= bst1[node];
		if(val > bst1[node]){
			bst2[node] = bst1[node];
			bst1[node] = val;
		}
		else if(val > bst2[node]){
			bst2[node] = val;
		}
		sum[node] += bst1[node];
	}
	if(!tmp[node]){
		sum[node] = 0;
		bst1[node] = 0;
		bst2[node] = 0;
	}
	ret |= (sum[node] >= k);
	for(int next : v[node]){
		if(next != parent){
			if(subtree1[next] == subtree2[next]){
				dfs2(next , node , sum[node] - subtree1[next]);
			}
			else if(bst1[node] == sum[next]){
				dfs2(next , node , sum[node] - bst1[node] + bst2[node]);
			}
			else{
				dfs2(next , node , sum[node]);
			}
		}
	}
}
bool check(int val){
	for(int i = 1 ; i <= n ; ++i){
		tmp[i] = (arr[i] >= val);
	}
	ret = 0;
	dfs(1 , 0);
	dfs1(1 , 0);
	if(ret){
		return 1;
	}
	dfs2(1 , 0 , 0);
	return ret;
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	int l = 1;
	int r = 1e6 + 1;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	printf("%d\n" , l - 1);
}