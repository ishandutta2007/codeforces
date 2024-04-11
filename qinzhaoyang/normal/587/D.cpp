#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 5e4 + 10;

struct Edge {int u, v, c, t;} e[N];
int n, m, cnt, l, r, dfn[N * 10], low[N * 10], c[N * 10], sta[N * 10], ins[N * 10], top, cur, col;
vector <int> G[N], g[N * 10], A;

void B(vector <int> &v, int flag) {
	int S , T;
	for(auto i : v) {
		int x = i, y = i + m, t = ++cnt, s = ++cnt;
		if(!flag) {
			g[x].pb(t) , g[s].pb(y);
			if(i != v[0]) g[T].pb(t), g[s].pb(S), g[x].pb(S), g[T].pb(y);
		}
		else {
			g[t].pb(x) , g[y].pb(s);
			if(i != v[0]) g[t].pb(T), g[S].pb(s), g[S].pb(x), g[y].pb(T);
		}
		S = s, T = t;
	}
}

void tarjan(int x) {
	dfn[x] = low[x] = ++cur, ins[sta[++top] = x] = 1;
	for(auto i : g[x]) {
		if(!dfn[i]) tarjan(i) , low[x] = min(low[x] , low[i]);
		else if(ins[i]) low[x] = min(low[x] , dfn[i]);
	}
	if(low[x] == dfn[x]) {
		c[x] = ++col;
		while(sta[top] != x)
			c[sta[top]] = col, ins[sta[top--]] = 0;
		ins[sta[top--]] = 0;
	}
}

int C(int v) {
	for(int i = 1; i <= m; i++) if(e[i].t > v) g[i].pb(i + m);
	for(int i = 1; i <= cnt; i++) dfn[i] = low[i] = c[i] = 0;
	cur = top = col = 0;
	for(int i = 1; i <= cnt; i++) if(!dfn[i]) tarjan(i);
	for(int i = 1; i <= m; i++) if(e[i].t > v) g[i].pop_back();
	for(int i = 1; i <= m; i++) if(c[i] == c[i + m]) return 0;
	return 1;
}

int main() {
	scanf("%d%d", &n, &m) , cnt = 2 * m;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].c, &e[i].t);
		G[e[i].u].pb(i) , G[e[i].v].pb(i) , r = max(r , e[i].t);
	}
	for(int i = 1; i <= n; i++) {
		sort(G[i].begin() , G[i].end() , [&](int A, int B){return e[A].c < e[B].c;});
		vector <int> s; B(G[i], 0);
		for(int j = 0; j < G[i].size(); j++) {
			s.pb(G[i][j]);
			while(j < G[i].size() - 1 && e[G[i][j]].c == e[G[i][j + 1]].c)
				s.pb(G[i][++j]); 
			B(s, 1), s.clear();
		}
	}
	if(!C(r)) return puts("No"), 0;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(C(mid)) r = mid;
		else l = mid + 1; 
	}
	C(l) , puts("Yes");
	for(int i = 1; i <= m; i++) if(c[i] < c[i + m]) A.pb(i);
	printf("%d %d\n", l, A.size());
	for(auto i : A) printf("%d ", i);
	puts("\n");
	return 0;
}