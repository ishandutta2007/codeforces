#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N] , b[N] , c[N];
vector < int > v[N];
int parent[N];
int depth[N];
int start , finish;
void dfs(int node , int parent , int level){
	depth[node] = level;
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(next != parent){
			if(depth[next]){
				start = node;
				finish = next;
			}
			else{
				::parent[next] = edge;
				dfs(next , node , level + 1);
			}
		}
	}
}
int cycle[N];
long long weight[N];
long long val[N];
long long dia;
int siz;
bool mark[N];
long long dfs2(int node , int parent){
	long long mx = 0;
	long long smx = 0;
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(next != parent && !mark[next]){
			long long ret = dfs2(next , node) + c[edge];
			if(ret > mx){
				smx = mx;
				mx = ret;
			}
			else if(ret > smx){
				smx = ret;
			}
		}
	}
	dia = max(dia , mx + smx);
	return mx;
}
long long pre[N];
long long suf[N];
long long sum[N];
long long get1[N];
long long get2[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %d" , a + i , b + i , c + i);
		v[a[i]].emplace_back(i);
		v[b[i]].emplace_back(i);
	}
	dfs(1 , 0 , 1);
	if(depth[finish] < depth[start]){
		swap(start , finish);
	}
	siz = 0;
	while(finish != start){
		++siz;
		cycle[siz] = finish;
		int edge = parent[finish];
		weight[siz] = c[edge];
		finish = a[edge] ^ b[edge] ^ finish;
	}
	++siz;
	cycle[siz] = start;
	for(int edge : v[start]){
		int next = a[edge] ^ b[edge] ^ start;
		if(next == cycle[1]){
			weight[siz] = c[edge];
		}
	}
	dia = 0;
	for(int i = 1 ; i <= siz ; ++i){
		mark[cycle[i]] = 1;
	}
	for(int i = 1 ; i <= siz ; ++i){
		val[i] = dfs2(cycle[i] , 0);
	}
	sum[0] = 0;
	sum[1] = 0;
	for(int i = 2 ; i <= siz ; ++i){
		sum[i] = sum[i - 1] + weight[i - 1];
	}
	pre[0] = 0;
	pre[1] = val[1];
	long long mx = val[1];
	for(int i = 2 ; i <= siz ; ++i){
		pre[i] = pre[i - 1];
		pre[i] = max(pre[i] , val[i] + sum[i] + mx);
		mx = max(mx , val[i] - sum[i]);
	}
	suf[siz + 1] = 0;
	suf[siz] = val[siz];
	mx = val[siz];
	for(int i = siz - 1 ; i >= 1 ; --i){
		suf[i] = suf[i + 1];
		suf[i] = max(suf[i] , val[i] + sum[siz] - sum[i] + mx);
		mx = max(mx , val[i] - (sum[siz] - sum[i]));
	}
	get1[0] = 0;
	get1[1] = val[1];
	for(int i = 2 ; i <= siz ; ++i){
		get1[i] = max(get1[i - 1] , val[i] + sum[i]);
	}
	get2[siz + 1] = 0;
	get2[siz] = val[siz];
	for(int i = siz - 1 ; i >= 1 ; --i){
		get2[i] = max(get2[i + 1] , val[i] + sum[siz] - sum[i]);
	}
	long long ans = max(dia , pre[siz]);
	for(int i = 1 ; i < siz ; ++i){
		long long res = dia;
		res = max(res , pre[i]);
		res = max(res , suf[i + 1]);
		res = max(res , get1[i] + get2[i + 1] + weight[siz]);
		ans = min(ans , res);
	}
	printf("%lld\n" , ans);
}