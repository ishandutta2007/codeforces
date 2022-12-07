#include <bits/stdc++.h>

using namespace std;

const int P = 2e6 + 1, N = 153456;

int prime[P], n, q, values[N], idx[P], curr, can[P], answer[N], done[N], depth[N];

vector < int > adj[N], factor[N];

void reset(){
	for(int i = 1; i <= curr; ++i){
		factor[i].clear();
	}
	for(int i = 1; i <= n; ++i){
		answer[i] = -1;
		done[i] = 0;
	}
}

void dfs2(int u){
	done[u] = 1;
	for(int v : adj[u]){
		if(done[v]) continue;
		depth[v] = depth[u] + 1;
		dfs2(v);
	}
}

void dfs(int u){
	done[u] = 1;

	int val = values[u];
	while(val > 1){
		int pr = prime[val];
		if(factor[idx[pr]].size() > 0){
			if(answer[u] == -1){
				answer[u] = factor[idx[pr]].back();
			}
			else{
				if(depth[answer[u]] < depth[factor[idx[pr]].back()]){
					answer[u] = factor[idx[pr]].back();
				}
			}
		}
		while(val % pr == 0){
			val /= pr;
		}
	}

	val = values[u];

	while(val > 1){
		int pr = prime[val];
		factor[idx[pr]].push_back(u);

	//	cout << u << " start is : " << values[u] << " -> current is " << val << " factor is " << pr << endl;

		while(val % pr == 0){
			val /= pr;
		}
	}
	
	for(int v : adj[u]){
		if(done[v] == 1) continue;
		dfs(v);	        
	}

	val = values[u];

	while(val > 1){
		int pr = prime[val];
		factor[idx[pr]].pop_back();
		while(val % pr == 0){
			val /= pr;
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("sol.inp", "r", stdin);
		freopen("sol.out", "w", stdout);
	#endif

	for(int i = 2; i < P; ++i){
		if(prime[i] != 0) continue;
		idx[i] = ++curr;
		can[curr] = i;
		for(int j = i; j < P; j += i){
			prime[j] = i;
		}
	}

	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i){
	    	scanf("%d", values + i);
	}

	for(int i = 1; i < n; ++i){
	        int u, v; scanf("%d%d", &u, &v);
	        adj[u].push_back(v);
	        adj[v].push_back(u);
	}
		
	dfs2(1); reset(); dfs(1);

	//return 0;

	for(int i = 1; i <= q; ++i){
		int type; scanf("%d", &type);
		if(type == 1){
			int ver; scanf("%d", &ver);
			printf("%d\n", answer[ver]);
		}
		else{
			int ver; 
			scanf("%d", &ver);
			scanf("%d", values + ver);

			reset(); dfs(1);
		}
	}

	return 0;
}