#include <bits/stdc++.h>

using namespace std;

const int maxn = 400;
bool mark[maxn], adj[maxn][maxn];
int h[maxn];
queue<int> Q;
int n, m;

int bfs(int st, bool isedge){
	Q.push(st);
	mark[st] = true;
	while(Q.size()){
			int v = Q.front();
			Q.pop();
			for(int u = 0; u < n; u++)
					if(!mark[u] and (adj[v][u] xor isedge))
							Q.push(u), h[u] = h[v] + 1, mark[u] = true;
	}
	return (mark[n - 1] ? h[n - 1] : -1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
			int fi, se;
			cin >> fi >> se;
			fi--, se--;
			adj[fi][se] = adj[se][fi] = true;
	}
	cout << bfs(0, adj[0][n - 1]) << endl;
	return 0;
}