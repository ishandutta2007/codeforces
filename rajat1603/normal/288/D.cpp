#include "bits/stdc++.h"
using namespace std;
const int N = 8e4 + 4;
int n;
int a , b;
vector < int > v[N];
int tin[N];
int tout[N];
int timer;
int sub[N];
void dfs0(int node , int parent){
	tin[node] = ++timer;
	sub[node] = 1;
	for(int next : v[node]){
		if(next != parent){
			dfs0(next , node);
			sub[node] += sub[next];
		}
	}
	tout[node] = timer;
}
inline int get(int root , int node , int last){
	if(root == node){
		return n;
	}
	if(tin[root] >= tin[node] && tout[root] <= tout[node]){
		return n - sub[last];
	}
	return sub[node];
}
long long ans;
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
int find(int node , int parent , int sz){
	for(int next : v[node]){
		if(next != parent && !done[next] && subtree[next] > sz){
			return find(next , node , sz);
		}
	}
	return node;
}
long long sqsum[N];
int centroid;
inline long long getc2(int node , int last){
	int tmp = get(centroid , node , last);
	return 1LL * tmp * (tmp - 1LL);
}
void dfs2(int node , int parent){
	sqsum[node] = 0;
	for(int next : v[node]){
		if(next != parent && !done[next]){
			dfs2(next , node);
		}
		if(next != parent){
			sqsum[node] += getc2(next , node);
		}
	}
}
long long tot;
int cnt;
void dfs3(int node , int parent , long long sum){
	sum += sqsum[node];
	ans += tot + cnt * sum;
	for(int next : v[node]){
		if(next != parent && !done[next]){
			dfs3(next , node , sum - getc2(next , node));
		}
	}
}
void dfs4(int node , int parent , long long sum){
	sum += sqsum[node];
	++cnt;
	tot += sum;
	for(int next : v[node]){
		if(next != parent && !done[next]){
			dfs4(next , node , sum - getc2(next , node));
		}
	}
}
void solve(int node){
	centroid = node;
	dfs2(node , 0);
	tot = 0;
	cnt = 1;
	for(int next : v[node]){
		if(!done[next]){
			dfs3(next , node , sqsum[node] - getc2(next , node));
			dfs4(next , node , -getc2(next , node));
		}
	}
}
void decompose(int node){
	dfs1(node , 0);
	int cent = find(node , 0 , subtree[node] >> 1);
	solve(cent);
	done[cent] = 1;
	for(int next : v[cent]){
		if(!done[next]){
			decompose(next);
		}
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dfs0(1 , 0);
	decompose(1);
	printf("%lld\n" , ans >> 1);
}