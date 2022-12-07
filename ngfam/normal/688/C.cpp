#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

vector < int > adj[N], ans[5];
int n, m, done[N];

void dfs(int u, int color){
	done[u] = color;
	int sz = adj[u].size();

//	cout << u << " " << color << endl;


	ans[color].push_back(u);
	for(int i = 0; i < sz; ++i){
		int v = adj[u][i];
		if(done[v]){
			if(done[v] != 3 - color){
				puts("-1");
				exit(0);
			}
			continue;
		}
		dfs(v, 3 - color);

	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("0.inp", "r", stdin);
		freopen("0.out", "w", stdout);	
	#endif
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);

	}

	for(int i = 1; i <= n; ++i){
		if(!done[i]){
			dfs(i, 1);
		}
	}

	printf("%d\n", int(ans[1].size()));
	for(int i = 0; i < ans[1].size(); ++i){
		printf("%d ", ans[1][i]);
	}
	printf("\n");
	printf("%d\n", int(ans[2].size()));
	for(int i = 0; i < ans[2].size(); ++i){
		printf("%d ", ans[2][i]);
	}
}