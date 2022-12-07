#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 1;

int n, q, fr[N], to[N], num, it[N * 8], lazy[N * 8], d, c, val, par[N];

vector < int > adj[N];

void dfs(int u){
	fr[u] = ++num;
	int sz = adj[u].size();
	for(int i = 0; i < sz; ++i){
		int v = adj[u][i];
		if(fr[v] != 0) continue;
		par[v] = u;
		dfs(v);
	}
	to[u] = num;
}

void solve(int i, int l, int r){
	if(lazy[i] != -1){
		it[i] = (r - l + 1) * lazy[i];
		lazy[i * 2] = lazy[i];
		lazy[i * 2 + 1] = lazy[i];
	}
	lazy[i] = -1;
}

void upd(int i, int l, int r){
	solve(i, l, r);
	if(d > r || l > c) return;
	if(l >= d && r <= c){
		lazy[i] = val;
		solve(i, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	upd(i * 2, l, mid);
	upd(i * 2 + 1, mid + 1, r);
	it[i] = it[i * 2] + it[i * 2 + 1];
}

int query(int i, int l, int r){
	solve(i, l, r);
	if(d > r || l > c) return 0;
	if(l >= d && r <= c) return it[i];
	int mid = (l + r) >> 1;
	return query(i * 2, l, mid) + query(i * 2 + 1, mid + 1, r);
}

void update(int l, int r, int values){
	d = l; c = r; val = values;
	upd(1, 1, n);
}

int ask(int l, int r){
	d = l; c = r; 
	return query(1, 1, n);
}

bool check(int l, int r){
	return ask(l, r) == (r - l + 1);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	memset(lazy, -1, sizeof lazy);

	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	dfs(1);

	scanf("%d", &q);
	while(q--){
		int quest, u;
		scanf("%d%d", &quest, &u);
		
		if(quest == 1){
			if(!check(fr[u], to[u])){
				if(par[u] != 0){
					update(fr[par[u]], fr[par[u]], 0);
				}
			}
			update(fr[u], to[u], 1);		
		}
		if(quest == 2){
			update(fr[u], fr[u], 0);
		}
		if(quest == 3){
			if(check(fr[u], to[u])){
				puts("1");
			}
			else{ 
				puts("0");
			}
		}
	}        

//	cout << it[1] << endl;

	return 0;
}