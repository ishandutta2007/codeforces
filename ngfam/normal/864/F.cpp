#include <bits/stdc++.h>

using namespace std;

const int N = 3001;
const int maxLog = 12;

typedef pair < int, int > data;

int n, m, q, cnt;
int low[N];
int mark[N];
int done[N];
int len[N][N];
set < int > current;
short ans[N][N][maxLog];
vector < int > adj[N]; 

void dfs(int u, int r){
	done[u] = 1;
	mark[u] = ++cnt;
	low[u] = mark[u] + 1;

	if(u == r) len[u][r] = 1;

	if(u != r && ans[r][u][0] != -1){
		for(int i = 1; i <= 11; ++i){
			ans[r][u][i] = ans[r][ans[r][u][i - 1]][i - 1];
		}
	}

	for(int v : adj[u]){
		if(mark[v]){
			if(done[v]) low[u] = min(low[u], mark[v]);
			continue;
		}

		if(ans[r][u][0] != -1 && low[u] > mark[u]){
		 ans[r][v][0] = u;
		 len[r][v] = len[r][u] + 1;
		}
		else ans[r][v][0] = -1;

		dfs(v, r);
		low[u] = min(low[u], low[v]);
	}
	done[u] = 0;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d%d", &n, &m, &q);

	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);

		adj[u].push_back(v);
	}

	for(int i = 1; i <= n; ++i){
		sort(adj[i].begin(), adj[i].end());
	}

	for(int st = 1; st <= n; ++st){
		memset(mark, 0, sizeof mark);

		dfs(st, st);
	}	

	while(q--){
		int s, t, k;
		scanf("%d%d%d", &s, &t, &k);

		if(ans[s][t][0] <= 0 || len[s][t] < k){
			puts("-1");
		 	continue;
		}


		for(int i = 11; i >= 0; --i){
			if(ans[s][t][i] == 0) continue;
			int x = ans[s][t][i];
			if(len[s][x] >= k){
				t = x;
			}
		}

		printf("%d\n", t);
	}

	return 0;
}