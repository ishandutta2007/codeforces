#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = N * 4;

int n, a[N], done[N], mx[N], mn[N], fr[N], to[N];
vector < int > adj[N];

struct segment{
	int it[M], lazy[M], d, c, val, n, ok;

	int combine(int u, int v){
		if(ok == true){
			return max(u, v);
		}
		return min(u, v);
	}

	void build(int i, int l, int r, int *a){
		if(l == r){
			it[i] = *(a + l);
			return;
		}
		int mid = (l + r) >> 1;
		build(i * 2, l, mid, a);
		build(i * 2 + 1, mid + 1, r, a);
		it[i] = combine(it[i * 2], it[i * 2 + 1]);
	}

	void solve(int i){
		if(lazy[i] != 0){
			it[i] += lazy[i]; 	
			if(i * 2 < M){
				lazy[i * 2] += lazy[i];
			}
			if(i * 2 + 1 < M){
				lazy[i * 2 + 1] += lazy[i];
			}
		}
		lazy[i] = 0;
	}

	void update(int i, int l, int r){
		if(d > r || l > c) return;
		if(l >= d && r <= c){
			lazy[i] = val;
			return;
		}
		int mid = (l + r) >> 1;
		update(i * 2, l, mid);
		update(i * 2 + 1, mid + 1, r);
		it[i] = combine(it[i * 2], it[i * 2 + 1]);
	}

	void upd(int l, int r, int values){
		d = l; c = r; val = values;
		update(1, 1, n);
	}

	int query(int i, int l, int r){
		if(d > r || l > c){
			if(ok) return 0;
			return N;
		};
		if(l >= d && r <= c) return it[i];
		int mid = (l + r) >> 1;
		return combine(query(i * 2, l, mid), query(i * 2 + 1, mid + 1, r));
	}

	int ask(int l, int r){
		if(l > r){
			if(ok == 1) return 0;
			return N;
		}
		d = l; c = r;
		return query(1, 1, n);
	}
}smtmax, smtmin;

int num, arr[N], tp[N];

void pre_dfs(int u){
	fr[u] = ++num;
	tp[fr[u]] = u;
	for(int v : adj[u]){
		if(fr[v] != 0) continue;
		pre_dfs(v);
	}
	to[u] = num;
}

void dfs(int u){
	done[u] = 1;
	bool child = true;
	mx[u] = mn[u] = a[u];
	for(int v : adj[u]){
		if(done[v]) continue;
		dfs(v);
		mx[u] = max(mx[u], mx[v]);
		mn[u] = min(mn[v], mn[u]);
		if(mn[v] != mx[v]){
			child = false;
		}
	}	
	if(child == true){
		int fmin = min(smtmin.ask(1, fr[u] - 1), smtmin.ask(to[u] + 1, n));
		int fmax = max(smtmax.ask(1, fr[u] - 1), smtmax.ask(to[u] + 1, n));
		//cout << u << " " << fr[u] << " " << to[u] << " " << fmax << " " << fmin << endl;
		if(fmin == fmax || u == 1){
			cout << "YES" << endl << u;
			exit(0);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v; 
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		mn[i] = n;
	}

	pre_dfs(1);

	smtmax.ok = 1;
	for(int i = 1; i <= n; ++i){
		arr[i] = a[tp[i]];
	}

	smtmax.build(1, 1, n, arr);
	smtmin.build(1, 1, n, arr);
	smtmax.n = smtmin.n = n;

//	cout << smtmax.ask(1, 2) << " " << smtmin.ask(1, 2) << endl;

	dfs(1);
	cout << "NO";
	return 0;
}