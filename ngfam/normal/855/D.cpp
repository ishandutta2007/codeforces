#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m, current;
int team[N];
int depth[N];
int jump[N][20];
int rmqmax[N][20];
int rmqmin[N][20];
vector < int > adj[N];

void dfs(int u){
	team[u] = current;

	for(int i = 1; i < 20; ++i){
		if(jump[u][i - 1] != -1){
			jump[u][i] = jump[jump[u][i - 1]][i - 1];
			rmqmax[u][i] = max(rmqmax[jump[u][i - 1]][i - 1], rmqmax[u][i - 1]);
			rmqmin[u][i] = min(rmqmin[jump[u][i - 1]][i - 1], rmqmin[u][i - 1]);
		}
	}

	for(int v : adj[u]){
		depth[v] = depth[u] + 1;
		dfs(v);
	}
}

int lca(int u, int v){
	if(depth[v] > depth[u]) swap(u, v);

	for(int i = 19; i >= 0; --i){
		if(jump[u][i] == -1) continue;
		if(depth[jump[u][i]] >= depth[v]) u = jump[u][i];
	}

	if(u == v) return u;

	for(int i = 19; i >= 0; --i){
		if(jump[u][i] == -1) continue;
		if(jump[u][i] != jump[v][i]){
			u = jump[u][i];
			v = jump[v][i];
		}
	}
	return jump[u][0];
}

pair < int, int > query(int u, int p, int add = 0){
	pair < int, int > ans = make_pair(-1e9, 1e9);
	for(int i = 19; i >= 0; --i){
		if(jump[u][i] == -1) continue;

		int x = jump[u][i];
		if(depth[x] + add < depth[p]) continue;

		ans.first = max(ans.first, rmqmax[u][i]);
		ans.second = min(ans.second, rmqmin[u][i]);

		u = jump[u][i];
	}

	return ans;
}

int last[N];

void re(int u){
}


int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);

	memset(jump, -1, sizeof jump);
	memset(rmqmin, 60, sizeof rmqmin);

	for(int i = 1; i <= n; ++i){
		int par, t;
		scanf("%d%d", &par, &t);

		jump[i][0] = par;
		rmqmax[i][0] = t;
		rmqmin[i][0] = t;

		if(par != -1) adj[par].push_back(i);
	}

	for(int i = 1; i <= n; ++i){
		if(jump[i][0] == -1){
			++current;
			dfs(i);
		}
	}

	scanf("%d", &m);

	while(m--){
		int t, u, v;
		scanf("%d%d%d", &t, &u, &v);

		if(team[u] != team[v]) puts("NO");
		else{
			int p = lca(u, v);

			pair < int, int > x = query(u, p), y =  query(v, p);

			if(v == p){
				puts("NO");
				continue;
			}
		
			if(t == 1){
				if(u != p){
					puts("NO");
					continue;
				}
				if(max(x.first, y.first) <= 0) puts("YES");
				else puts("NO"); 
			}
			else{
				if(y.second >= 1 && (x.first <= 0)) puts("YES");
				else puts("NO");
			}
		}
	}


	return 0;
}