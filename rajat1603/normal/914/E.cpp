#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int a , b;
vector < int > v[N];
char str[N];


bool done[N];
int subtree[N];
void dfs1(int node , int parent){
	subtree[node] = 1;
	for(int next : v[node]){
		if(next != parent && !done[next]){
			dfs1(next , node);
			subtree[node] += subtree[next];
		}
	}
}
int find(int node , int parent , int val){
	for(int next : v[node]){
		if(next != parent && !done[next] && subtree[next] > val){
			return find(next , node , val);
		}
	}
	return node;
}
void solve(int centroid);
void go(int node){
	dfs1(node , 0);
	int centroid = find(node , 0 , subtree[node] >> 1);
	solve(centroid);
	done[centroid] = 1;
	for(int next : v[centroid]){
		if(!done[next]){
			go(next);
		}
	}
}

long long ans[N];
const int LN = 21;
const int SZ = 1 << LN;
int freq[SZ];
int when[SZ];
int timer;
void dfs2(int node , int parent , int val , int add){
	val ^= 1 << (str[node] - 'a');
	if(when[val] != timer){
		when[val] = timer;
		freq[val] = 0;
	}
	freq[val] += add;
	for(int next : v[node]){
		if(next != parent && !done[next]){
			dfs2(next , node , val , add);
		}
	}
}
long long sum;
long long dfs3(int node , int parent , int val){
	val ^= 1 << (str[node] - 'a');
	long long tot = 0;
	for(int i = 0 ; i < LN ; ++i){
		int need = val ^ (1 << i);
		if(when[need] == timer){
			tot += freq[need];
		}
		if(!need){
			++tot;
			++sum;
		}
	}
	if(when[val] == timer){
		tot += freq[val];
	}
	if(!val){
		++tot;
		++sum;
	}
	for(int next : v[node]){
		if(next != parent && !done[next]){
			tot += dfs3(next , node , val);
		}
	}
	ans[node] += tot;
	return tot;
}
void solve(int centroid){
	++timer;
	for(int next : v[centroid]){
		if(!done[next]){
			dfs2(next , centroid , 0 , 1);
		}
	}
	sum = 0;
	for(int next : v[centroid]){
		if(!done[next]){
			dfs2(next , centroid , 0 , -1);
			sum += dfs3(next , centroid , 1 << (str[centroid] - 'a'));
			dfs2(next , centroid , 0 , 1);
		}
	}
	sum >>= 1;
	ans[centroid] += sum;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	scanf("%s" , str + 1);
	go(1);
	for(int i = 1 ; i <= n ; ++i){
		printf("%lld%c" , ans[i] + 1 , " \n"[i == n]);
	}
}