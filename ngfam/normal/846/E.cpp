#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
long long sum = 0;
long long f[N];
vector < pair < int, int > > adj[N];

long long mul(long long u, long long v){
	if(v == 0){
		return 0;
	}
	if((sum + abs(v) - 1) / abs(v) <= abs(u)){
		puts("NO");
		exit(0);
	}
	return u * v;
}

long long dfs(int u){
	for(int i = 0; i < adj[u].size(); ++i){
		int v = adj[u][i].first, w = adj[u][i].second;
		dfs(v);
		if(f[v] > 0){
			f[u] += f[v];
		}
		else{
			f[u] += mul(f[v], w);
		}
	}
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);


	for(int i = 1; i <= n; ++i){
		long long x;
		scanf("%lld", &x);
		f[i] += x;
		sum += x;
	}
	
	for(int i = 1; i <= n; ++i){
		long long x;
		scanf("%lld", &x);
		f[i] -= x;
	}

	for(int i = 2; i <= n; ++i){
		int u, w;
		scanf("%d%d", &u, &w);
		adj[u].push_back(make_pair(i, w));
	}

	dfs(1);
	if(f[1] >= 0){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}