#include<bits/stdc++.h>
using namespace std;
#define MN 100005
#define ll long long
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int N, Ans;
vector<int> G[MN];
int f[MN], g[MN];
// f[u] : dis<=1 u
// g[u] : dis<=1 u
void DFS(int u, int p) {
	int cntch = 0;
	for (int v : G[u]) if (v != p) ++cntch, DFS(v, u);
	if (!cntch) {
		f[u] = 1, g[u] = 0;
		return ;
	}
	if (cntch == 1) {
		for (int v : G[u]) if (v != p) f[u] = g[v] + 1, g[u] = max(f[v], g[v]);
		Ans = max(Ans, max(f[u], g[u] + (p != 0)));
		return ;
	}
	int a1 = 0, a2 = 0;
	int b1 = 0, b2 = 0;
	f[u] = 1, g[u] = 0;
	for (int v : G[u]) if (v != p) {
		a2 = max(a2, g[v]);
		if (a2 > a1) swap(a1, a2);
		b2 = max(b2, max(f[v], g[v]));
		if (b2 > b1) swap(b1, b2);
		f[u] = max(f[u], g[v] + 1);
		g[u] = max(g[u], max(f[v], g[v]) + cntch - 1);
	}
	int val = max(a1 + a2 + 1, b1 + b2 + cntch - 2 + (p != 0));
	Ans = max(Ans, val);
//	printf("(f, g, val)[%d] = (%d, %d, %d)\n", u, f[u], g[u], val);
}
int main() {
	scanf("%d", &N), Ans = 1;
	for (int i = 1, x, y; i < N; ++i) {
		scanf("%d%d", &x, &y);
		G[x].pb(y), G[y].pb(x);
	}
	DFS(1, 0);
	printf("%d\n", Ans);
	return 0;
}

/*
13
1 2
2 3
3 4
4 5
1 6
6 7
7 8
8 9
1 10
10 11
11 12
12 13
*/