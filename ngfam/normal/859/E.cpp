#include <bits/stdc++.h>

using namespace std;

const int N = 200101;
const long long mod = 1e9 + 7;

int n;
int lead[N];
int child[N];
int done[N];
vector < int > adj[N];
vector < int > gra[N];

void pre_dfs(int u){
	child[u] = 1;
	done[u] = 1;
	for(int i = 0; i < adj[u].size(); ++i){
		int v = adj[u][i];
		pre_dfs(v);
		child[u] += child[v];
	}	
}

long long Tree(int u){
	int sum = 1;
	if(child[u] == 1){
		return 1;
	}	
	for(int i = 0; i < adj[u].size(); ++i){
		int v = adj[u][i];
		sum += Tree(v);
		sum %= mod;
	}
	return sum;
}

void cycle(int u){
	done[u] = 1;
	for(int i = 0; i < gra[u].size(); ++i){
		int v = gra[u][i];
		if(done[v] == 1){
			continue;;
		}
		cycle(v);
	}
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);

	for(int i = 1; i <= n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);

		if(u == v){
			done[u] = 1;
		}

		adj[v].push_back(u);
		gra[u].push_back(v);
		gra[v].push_back(u);
		lead[u] = v;
	}	

	for(int i = 1; i <= 2 * n; ++i){
		if(done[i]){
			cycle(i);
		}
	}

	long long ans = 1;

	for(int i = 1; i <= 2 * n; ++i){
		if(lead[i] == 0 && !done[i]){
			pre_dfs(i);

			ans = ans * (child[i] );
			ans %= mod;
		}
	}

	for(int i = 1 ; i <= 2 * n; ++i){
		if(done[i] == 0){
			ans = ans * 2;
			ans %= mod;
			cycle(i);
		}
	}

	cout << ans;

	return 0;
}