#include "bits/stdc++.h"
using namespace std;
const int LN = 16;
const int N = 1 << LN;
int n , q;
int arr[N];
int a , b;
vector < int > v[N];
int siz[1 << LN];
int anc[N];
int parent[N];
int path[N];
int level;
int bst[N][256];
int depth[N];
int pre[N][200];

void update(int val , int add){
	int node = 1;
	for(int i = 7 ; i >= 0 ; --i){
		node = node + node + ((val >> i) & 1);
		siz[node] += add;
	}
}

inline int query(int val){
	int node = 1;
	int res = 0;
	for(int i = 7 ; i >= 0 ; --i){
		bool b = !((val >> i) & 1);
		if(siz[node + node + b]){
			node = node + node + b;
			res ^= 1 << i;
		}
		else{
			node = node + node + (!b);
		}
	}
	return res;
}
void dfs1(int node , int parent){
	path[++level] = node;
	depth[node] = level;
	for(int j = level ; j > level - 256 && j > 0 ; --j){
		int x = path[j];
		bst[node][arr[x] >> 8] = max(bst[node][arr[x] >> 8] , (arr[x] & 255) ^ (level - j));
	}
	anc[node] = path[max(0 , level - 256)];
	::parent[node] = parent;
	update(arr[node] >> 8 , 1);
	if(anc[node]){
		update(arr[anc[node]] >> 8 , -1);
	}
	for(int i = 0 ; i < 200 ; ++i){
		pre[node][i] = query(i);
	}
	for(int next : v[node]){
		if(next != parent){
			dfs1(next , node);
		}
	}
	path[level--] = 0;
	if(anc[node]){
		update(arr[anc[node]] >> 8 , 1);
	}
	update(arr[node] >> 8 , -1);
}


void query(int up , int dwn){
	int cur = 0;
	int node = dwn;
	int mx = 0;
	int res = 0;
	while(node){
		if(depth[up] > depth[node] - 255){
			break;
		}
		mx = max(mx , pre[node][cur]);
		res = max(res , bst[node][mx ^ cur] ^ (mx << 8));
		++cur;
		node = anc[node];
	}
	if(depth[up] <= depth[node]){
		cur <<= 8;
		while(node != up){
			res = max(res , arr[node] ^ cur);
			++cur;
			node = parent[node];
		}
		res = max(res , arr[node] ^ cur);
	}
	printf("%d\n" , res);
}

int main(){
	scanf("%d %d" , &n , &q);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dfs1(1 , 0);
	while(q--){
		scanf("%d %d" , &a , &b);
		query(a , b);
	}
}