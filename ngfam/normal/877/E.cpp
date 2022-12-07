#include <bits/stdc++.h>
#define mid ((l + r) >> 1)

using namespace std;

const int N = 2e5 + 10;

int it[N * 8];
int lazy[N * 8];

void push(int x, int l, int r){
	if(lazy[x] != 0){
		it[x] = (r - l + 1) - it[x];
		lazy[x + x] ^= 1;
		lazy[x + x + 1] ^= 1;
	}
	lazy[x] = 0;
}

void upd(int x, int l, int r, int u, int v){
	push(x, l, r);
	if(l > v || r < u) return;
	if(l >= u && r <= v){
		lazy[x] ^= 1;
		push(x, l, r);
		return;
	}
	upd(x + x, l, mid, u, v);
	upd(x + x + 1, mid + 1, r, u, v);
	it[x] = it[x + x] + it[x + x + 1];
}

int query(int x, int l, int r, int u, int v){
	push(x, l, r);
	if(l > v || r < u) return 0;
	if(l >= u && r <= v) return it[x];

	int ans = query(x + x, l, mid, u, v) + query(x + x + 1, mid + 1, r, u, v);
	it[x] = it[x + x] + it[x + x + 1];
	return ans;
}

int n, now;
int a[N];
int l[N];
int r[N];
int rev[N];
vector < int > adj[N];

void build(int x, int l, int r){
	if(l == r){
		int u = rev[r];
		it[x] = a[u];
		return;
	}

	build(x + x, l, mid);
	build(x + x + 1, mid + 1, r);
	it[x] = it[x + x] + it[x + x + 1];

}

void dfs(int u){
	l[u] = ++now;
	rev[now] = u;
	for(int v : adj[u]){
		dfs(v);
	}
	r[u] = now;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);

	for(int i = 2; i <= n; ++i){
		int p;
		scanf("%d", &p);
		adj[p].push_back(i);
	}

	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	dfs(1);
	build(1, 1, n);

	int m;
	scanf("%d", &m);

	while(m--){
		int u;
		char read[5];
		scanf("%s%d", &read, &u);
		if(read[0] == 'g'){
			printf("%d\n", query(1, 1, n, l[u], r[u]));
		}
		else{
			upd(1, 1, n, l[u], r[u]);
		}
	}

	return 0;
}