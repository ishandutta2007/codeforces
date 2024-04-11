#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10; 

void GG() {
	cout << "No" << endl , exit(0);
}

struct Edge {int nxt , to;} e[N << 1];
int first[N] , cur = 1 , f[N << 1];
void con(int x , int y) {e[++cur] = (Edge){first[x] , y} , first[x] = cur;}

int n , m , q , x[N] , y[N];
int dfn[N] , low[N] , cnt_dfn;
int col[N] , cnt;

void tarjan(int x , int fa) {
	dfn[x] = low[x] = ++cnt_dfn;
	for(int i = first[x]; i; i = e[i].nxt) {
		int to = e[i].to;
		if(to == fa) continue;
		if(!dfn[to]) {
			tarjan(to , x);
			low[x] = min(low[x] , low[to]);
			if(low[to] > dfn[x])
				f[i] = f[i ^ 1] = 1;
		}
		else
			low[x] = min(low[x] , dfn[to]);
	}
}

void dfs(int x) {
	col[x] = cnt;
	for(int i = first[x]; i; i = e[i].nxt) {
		int to = e[i].to;
		if(!col[to] && !f[i])
			dfs(to);
	}
}

vector <int> G[N];
map <pair<int,int>,int> hav;

int vis[N] , fa[N][21] , dep[N];
int up[N] , down[N];

void build(int x , int f) {
	fa[x][0] = f , dep[x] = dep[f] + 1 , vis[x] = 1;
	for(int i = 1; i <= 20; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for(auto i : G[x]) if(i != f) build(i , x);
}

int Lca(int x , int y) {
	if(dep[x] < dep[y]) swap(x , y);
	for(int i = 20; i >= 0; i--)
		if(dep[fa[x][i]] >= dep[y])
			x = fa[x][i];
	if(x == y) return x;
	for(int i = 20; i >= 0; i--)
		if(fa[x][i] != fa[y][i])
			x = fa[x][i] , y = fa[y][i];
	return fa[x][0];
}

void check(int x) {
	for(int i : G[x]) if(i != fa[x][0]) 	
		check(i) , up[x] += up[i] , down[x] += down[i];
	if(up[x] && down[x]) GG();
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for(int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i];
		con(x[i] , y[i]) , con(y[i] , x[i]);
	}
	for(int i = 1; i <= n; i++)
		if(!dfn[i]) tarjan(i , 0);
	for(int i = 1; i <= n; i++)
		if(!col[i]) ++cnt , dfs(i);
	for(int i = 1; i <= m; i++) {
		int u = col[x[i]] , v = col[y[i]];
		if(u != v && !hav[make_pair(u , v)]) {
			G[u].push_back(v) , G[v].push_back(u);
			hav[make_pair(u , v)] = hav[make_pair(v , u)] = 1;
		}
	}
	for(int i = 1; i <= cnt; i++)
		if(!vis[i]) build(i , 0);
	for(int i = 1 , s , t; i <= q; i++) {
		cin >> s >> t; s = col[s] , t = col[t];
		int l = Lca(s , t);
		if(!l) GG();
		up[s]++ , down[t]++;
		up[l]-- , down[l]--;
	}
	for(int i = 1; i <= n; i++) if(!fa[i][0]) check(i);
	cout << "Yes" << endl; return 0;
}