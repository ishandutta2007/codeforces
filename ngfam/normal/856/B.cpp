#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int n;

int len[N];
int failure[N];
int edge[N][30];

char read[N];

int dp[N][2];


vector < int > adj[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int nTest;
	scanf("%d", &nTest);

	while(nTest--){
		scanf("%d", &n);

		int cnt = 0;


		for(int i = 1; i <= n; ++i){
			scanf("%s", read);

			int node = 0, m = strlen(read);
			
			for(int j = 0; j < m; ++j){
				int x = read[j] - 'a';
				if(edge[node][x] == 0){
					edge[node][x] = ++cnt;
				}
				node = edge[node][x];
			}
		}

		int save = cnt;

		for(int i = 0; i < 26; ++i){
			if(edge[0][i] == 0){
				edge[0][i] = ++cnt;
			}
		}


		for(int i = 0; i <= cnt; ++i){
			adj[i].clear();
		}

		queue < int > bfs;
		bfs.push(0);

		stack < int > topo;

		while(!bfs.empty()){
			int x = bfs.front();
			bfs.pop();

			topo.push(x);

			for(int i = 0; i < 26; ++i){
				if(edge[x][i] == 0) continue;

				if(x != 0){
					int fail = failure[x];
					while(edge[fail][i] == 0) fail = failure[fail];
					failure[edge[x][i]] = edge[fail][i];
				}
				len[edge[x][i]] = len[x] + 1;
				bfs.push(edge[x][i]);
			}
		}


		int ans = 0;

		while(!topo.empty()){
			int i = topo.top();
			topo.pop();

			int zero = 0, one = 0;
			for(int x : adj[i]){
				zero = zero + dp[x][0];
				one = one + max(dp[x][0], dp[x][1]);
			}


			dp[i][0] = one;
			dp[i][1] = zero + (i <= save && i != 0);


			int x = failure[i];
			if(len[x] + 1 == len[i]) adj[x].push_back(i);
			else ans += max(dp[i][0], dp[i][1]);
		}

		for(int i = 0; i <= cnt; ++i){
			len[i] = failure[i] = dp[i][0] = dp[i][1] = 0;
			for(int z = 0; z < 26; ++z){
				edge[i][z] = 0;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}