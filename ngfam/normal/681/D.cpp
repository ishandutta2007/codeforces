#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int n, m, a[N], child[N], appear[N], father[N];
vector < int > adj[N], ans, gra[N]; 


int fr[N], to[N], cur, level[N];

void dfs(int u){
	fr[u] = ++cur;
	int sz = adj[u].size();

	gra[level[u]].push_back(u);

	for(int i = 0; i < sz; ++i){
		int v = adj[u][i];
		level[v] = level[u] + 1;
		dfs(v);
	}
	to[u] = cur;
}

int riki[N], it[N * 5], ok[N];

void build(int i, int l, int r){
	if(l == r){
		it[i] = riki[l];
		return;	
	}
	
	int mid = (l + r) >> 1;
	build(i * 2, l, mid);
	build(i * 2 + 1, mid + 1, r);

	it[i] = min(it[i * 2], it[i * 2 + 1]);
}

int d, c;

int query(int i, int l, int r){
	if(l > c || d > r) return N;
	if(l >= d && r <= c) return it[i];
	int mid = (l + r) >> 1;
	return min(query(i * 2, l, mid), query(i * 2 + 1, mid + 1, r));
}

int ask(int l, int r){
	if(l > r) return N;
	d = l; c = r;
	return query(1, 1, n);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		
		father[v] = u;
		adj[u].push_back(v);
		++child[u];
	}

	for(int i = 1; i <= n; ++i){
		if(father[i] == 0) dfs(i);
	}

	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		appear[a[i]] = 1;	
		riki[fr[i]] = fr[a[i]];
	}

	build(1, 1, n);
	//return 0;

	for(int i = n - 1; i >= 0; --i){
		int sz= gra[i].size();
		
		for(int j = 0; j < gra[i].size(); ++j){
				
			int u = gra[i][j];

			if(appear[u]){
				 ans.push_back(u);

				 if(ask(fr[u] + 1, to[u]) < fr[u]){
					puts("-1");
			 		return 0;
				 }
	        	}
		}

	}
	
	printf("%d\n", ans.size());

	for(int i = 0; i < ans.size(); ++i){
		printf("%d\n", ans[i]);
	}

	return 0;
}