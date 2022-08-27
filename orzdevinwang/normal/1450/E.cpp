#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 207;
const int inf = 1e9 + 7;
int n, m, P[N][N], G[N][N], maxn = -inf, st, col[N];
void dfs(int x) {
	L(i, 1, n) if(P[x][i]) {
		if(!col[i]) col[i] = 3 - col[x], dfs(i);
		else if(col[i] != 3 - col[x]) return puts("NO"), exit(0), void();
	}
}
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, n) L(j, 1, n) G[i][j] = inf * (i != j);
	L(i, 1, m) {
		int u, v, opt; scanf("%d%d%d", &u, &v, &opt);
		P[u][v] = P[v][u] = 1;
		if(opt == 1) G[u][v] = min(G[u][v], 1), G[v][u] = -1;
		else G[u][v] = min(G[u][v], 1), G[v][u] = min(G[v][u], 1);
	}
	col[1] = 1, dfs(1);
	L(k, 1, n) L(i, 1, n) L(j, 1, n) G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
	L(i, 1, n) if(G[i][i] < 0) return puts("NO"), 0;
	L(i, 1, n) L(j, 1, n) if(G[i][j] > maxn) maxn = G[i][j], st = i;
	printf("YES\n%d\n", maxn);
	L(i, 1, n) printf("%d ", G[st][i]);
	puts("");
	return 0;
}