#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int jump[N][20], n, root, from[N], to[N], cur, level[N], a[N];

vector < int > adj[N];

void dfs(int u){
	from[u] = ++cur;
	a[cur] = level[u];
	int sz = adj[u].size();
	for(int i = 0; i < sz; ++i){
		int v = adj[u][i];
		level[v] = level[u] + 1;
		dfs(v);
	}
	to[u] = cur;
}

vector < int > it[N * 4];

void build(int i, int l, int r){
	if(l == r){
		it[i].push_back(a[l]);
		return;
	}
	int mid = (l + r) >> 1, ii = i << 1;
	build(ii, l, mid);
	build(ii + 1, mid + 1, r);
	
	it[i].resize(it[ii].size() + it[ii + 1].size());
	merge(it[ii].begin(), it[ii].end(), it[ii + 1].begin(), it[ii + 1].end(), it[i].begin()); 
}

int d, c, how;

int query(int i, int l, int r){
	if(l > c || d > r) return 0;
	if(l >= d && r <= c){
	   	int finl = lower_bound(it[i].begin(), it[i].end(), how) - it[i].begin();
	   	int finr = upper_bound(it[i].begin(), it[i].end(), how) - it[i].begin();
	   	return finr - finl;
	}       	
	
	int mid = (l + r) >> 1, ii = i << 1;
	return query(ii, l, mid) + query(ii + 1, mid + 1, r);
}       	

int ask(int l, int r, int val){
	d = l; c = r; how = val;
	return query(1, 1, n);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int val; scanf("%d", &val);
		if(val != 0){
			jump[i][0] = val;
			adj[val].push_back(i);
		}
	}

	//dfs(root);
	
	for(int i = 1; i <= n; ++i){
		if(jump[i][0] == 0) dfs(i);
	}

	for(int j = 1; j <= 19; ++j){
		for(int i = 1; i <= n; ++i){
			jump[i][j] = jump[jump[i][j - 1]][j - 1];
		}
	}
	
	build(1, 1, n);

	int m; scanf("%d", &m);

	for(int i = 1; i <= m; ++i){
		int u, k;
		scanf("%d%d", &u, &k);
	//	++k;

		int par = u;
		for(int i = 19; i >= 0; --i){
			if((1 << i) <= k){
				par = jump[par][i];
				k -= 1 << i;
			}
		}

		if(par == 0){
			 printf("0 ");
		//	 if(n == 100000) puts("YES");
		}
		else{
			printf("%d ", ask(from[par], to[par], level[u]) - 1);
		}
	}

	return 0;
}