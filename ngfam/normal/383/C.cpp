#include <bits/stdc++.h>

using namespace std;

const int N = 234567;

int n, q, fr[N], to[N], start[N], curr, depth[N];

struct fenwick{
  	int bit[N];

	void upd(int i, int val){
		for(; i < N; i += i & -i){
			bit[i] += val;
		}
	}

	int ask(int i){
		int result = 0;
		for(; i > 0; i &= i - 1){
			result += bit[i];
		}
		return result;
	}
}fwt[2];

vector < int > adj[N];

void dfs(int u){
	fr[u] = ++curr;
	for(int v : adj[u]){
		if(fr[v] != 0) continue;
		depth[v] = depth[u] + 1;
		dfs(v);
	}
	to[u] = curr;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("sol.inp", "r", stdin);
		freopen("sol.out", "w", stdout);
	#endif

	scanf("%d%d", &n, &q);

	for(int i = 1; i <= n; ++i){
		scanf("%d", start + i);
	}

	for(int i = 1; i < n; ++i){
		int u, v;
 		scanf("%d%d", &u, &v);
 		adj[u].push_back(v);
 		adj[v].push_back(u);
	}

	dfs(1);

	for(int i = 1; i <= q; ++i){
		int type; scanf("%d", &type);
		if(type == 1){
			int ver, val;
			scanf("%d%d", &ver, &val);
			fwt[depth[ver] % 2].upd(fr[ver], val);
			fwt[depth[ver] % 2].upd(to[ver] + 1, -val);
			fwt[1 - depth[ver] % 2].upd(fr[ver], -val);
			fwt[1 - depth[ver] % 2].upd(to[ver] + 1, val);
		}
		else{
			int ver; scanf("%d", &ver);
			printf("%d\n", fwt[depth[ver] % 2].ask(fr[ver]) + start[ver]);
		}	
	}
	
	return 0;
}