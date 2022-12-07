#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, m;
int par[N];
bool e[N][N];
int current[N];
int visited[N];
vector < int > cycle;


int TIME;


void dfs(int u){
	++current[u];
		if(cycle.size()) return;
	visited[u] = TIME;
	for(int v = 1; v <= n; ++v){
		if(cycle.size()) return;
		if(e[u][v] == 0) continue;

		if(visited[v]){
			
			if(!current[v]) continue;

			int x = u;
			while(true){
				cycle.push_back(x);
				if(x == v) break;
				x = par[x];
			}
			reverse(cycle.begin(), cycle.end());
			cycle.push_back(v);

			return;
		}
		else{
			par[v] = u;
			dfs(v);
			if(cycle.size()) return;
		}
	}
	--current[u];
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		e[u][v] = 1;
	}

	for(int i = 1; i <= n; ++i){
		if(!visited[i]){
			++TIME;
			dfs(i);
		}
	}

	vector < int > save = cycle;


	if(!save.size()){
		cout << "YES";
		return 0;
	}


	for(int i = 1; i < save.size(); ++i){
		int x = save[i - 1], y = save[i];

		cycle.clear();
		e[x][y] = 0;

		TIME = 0;
		memset(current, 0, sizeof current);
		memset(visited, 0, sizeof visited);

		for(int i = 1; i <= n; ++i){
			if(!visited[i]){
				++TIME;
				dfs(i);
				if(cycle.size()) break;
			}
		}

		if(cycle.empty()){
			cout  << "YES";
			exit(0);
		}

		e[x][y] = 1;
	}

	cout << "NO";

	return 0;
}