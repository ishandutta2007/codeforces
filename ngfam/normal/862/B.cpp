#include <bits/stdc++.h>

using namespace std;

const int N = 101010;

int n;
long long odd = 0;
long long even = 0;
int f[N];
vector < int > adj[N];

void dfs(int u, int p = 0){
	f[u] = f[p] + 1;
	
	if(f[u] & 1) ++odd;
	else ++even;

	for(int v : adj[u]){
		if(v == p){
			continue;
		}
		dfs(v, u);
	}
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	cout << odd * even - n + 1;

	return 0;
}