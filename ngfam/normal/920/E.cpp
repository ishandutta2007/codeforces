#include <bits/stdc++.h>

using namespace std;

const int N = 200200;

int n, m;
int mark[N];
vector < int > e[N];
list < int > g[N * 5];

#define mid ((l + r) >> 1)

void build(int x, int l, int r, int u, int v, int ver){
	if(u > v) return;
	if(l >= u && r <= v){
		g[x + n].push_back(ver);
		return;
	}
	if(l > v || r < u) return;
	build(x + x, l, mid, u, v, ver);
	build(x + x + 1, mid + 1, r, u, v, ver);
}

void fix(int x, int l, int r){
	if(l == r) {
		g[x + n].push_back(r);
		return;
	}
	if(g[x + n].size()){
		g[x + n].push_back(x + x + n);
		g[x + n].push_back(x + x + 1 + n);
		g[x + x + n].push_back(x + n);
		g[x + x + 1 + n].push_back(x + n);
	}
	fix(x + x, l, mid);
	fix(x + x + 1, mid + 1, r);
}

int val[N * 5];
int lab[N * 5];

int par(int u){
	return (lab[u] < 0 ? u : lab[u] = par(lab[u]));
}

void join(int u, int v){
	u = par(u); v = par(v);
	if(u == v) return;
	if(lab[u] > lab[v]) swap(u, v);
	val[u] += val[v];
	lab[u] += lab[v];
	lab[v] = u;
}	

int main(){

	scanf("%d%d", &n, &m);

	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);

		e[u].push_back(v);
		e[v].push_back(u);
	}

	for(int i = 1; i <= n; ++i){
		val[i] = 1;
		sort(e[i].begin(), e[i].end());
		e[i].push_back(n + 1);

		int last = 0;
		for(int x : e[i]){
			build(1, 1, n, last + 1, x - 1, i);
			last = x;
		}
	}

	fix(1, 1, n);

	memset(lab, -1, sizeof lab);


	for(int i = 1; i < N * 5; ++i){
		for(int x : g[i]){
			join(x, i);
		}
	}

	vector < int > ans;
	for(int i = 1; i < N * 5; ++i){
		if(par(i) == i){
			if(val[par(i)]) ans.push_back(val[par(i)]);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for(int x : ans) cout << x << " ";

	return 0;
}