//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Iz wayTn' 230u :)

#define PB push_back
#define sz(x) ((int)(x).size())

const int maxn = 1e5 + 10, maxl = 20, MINF = 1000 * 1000;
int par[maxn][maxl];
vector<int> adj[maxn];
vector<int> peop[maxn];
int h[maxn];
int n, m, q;

struct ABOO{
	int a[10];
	ABOO(){
		for(int i = 0; i < 10; i++)
			a[i] = MINF;
	}
	int &operator[](int i){
		return a[i];
	}
} people[maxn][maxl];

ABOO operator^(ABOO &X, ABOO &Y){
	ABOO Z;
	int p = 0, q = 0;
	for(int i = 0; i < 10; i++){
		if(p == 10)
			Z[i] = Y[q++];
		else if(q == 10)
			Z[i] = X[p++];
		else if(X[p] < Y[q])
			Z[i] = X[p++];
		else
			Z[i] = Y[q++];
	}
	return Z;
}

void dfs(int v, int p = -1){
	par[v][0] = p;
	for(int i = 1; i < maxl and par[v][i - 1] != -1; i++)
		par[v][i] = par[par[v][i - 1]][i - 1];
	for(int i = 0; i < 10; i++)
		people[v][0][i] = peop[v][i];
	for(int i = 1; (1 << i) <= h[v] + 1; i++)
		people[v][i] = people[v][i - 1] ^ people[par[v][i - 1]][i - 1];
	for(int i = 0; i < sz(adj[v]); i++){
		int u = adj[v][i];
		if(u != p){
			h[u] = h[v] + 1;
			dfs(u, v);
		}
	}
	return;
}

int lca(int v, int u){
	if(h[v] < h[u])
		swap(v, u);
	for(int i = 0; h[v] - h[u]; i++)
		if(((h[v] - h[u]) >> i) & 1)
			v = par[v][i];
	if(v == u)
		return v;
	for(int i = maxl - 1; i >= 0; i--)
		if(par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

ABOO get(int v, int dis){
	ABOO ret;
	for(int i = 0; i < maxl; i++)
		if((dis >> i) & 1){
			ret = ret ^ people[v][i];
			v = par[v][i];
		}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> m >> q;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		peop[x].PB(i + 1);
	}
	for(int i = 1; i <= n; i++){
		sort(peop[i].begin(), peop[i].end());
		while(sz(peop[i]) > 10)
			peop[i].pop_back();
		while(sz(peop[i]) < 10)
			peop[i].PB(MINF);
	}
	dfs(1);
	/*for(int i = 1; i <= n; i++){
		cout << i << ": ";
		for(int j = 0; j < 10; j++)
			cout << people[i][0][j] << ' ';
		cout << endl;
	}*/
	for(int i = 0; i < q; i++){
		int v, u, a;
		cin >> v >> u >> a;
		int p = lca(v, u);
		ABOO A1 = get(v, h[v] - h[p]),
			 A2 = get(u, h[u] - h[p]),
			 A3 = get(p, 1);
		ABOO A4, A5;
		A4 = A1 ^ A2;
		A5 = A4 ^ A3;
		int cnt = 0;
		for(int i = 0; i < a and A5[i] != MINF; i++)
			cnt++;
		cout << cnt << ' ';
		for(int i = 0; i < cnt; i++)
			cout << A5[i] << ' ';
		cout << '\n';
	}
	return 0;
}