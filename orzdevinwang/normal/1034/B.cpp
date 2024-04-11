#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define N 2100
#define M 50009
using namespace std;
bool vis[N];
int pp[N];
int head[N];
struct node{
	int to, next;
} e[M];
int edge_id;
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
bool dfs(int x) {
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(vis[v]) continue;
		vis[v] = 1;
		if(!pp[v] || dfs(pp[v])) {
			pp[v] = x;
			return 1;
		} 
	}
	return 0;
}
#define P(i, j) ((i - 1) * y + (j)) 
int get(int x, int y) {
	int res = 0;
	L(i, 1, x) L(j, 1, y) {
		if((i + j) % 2 == 1) continue;
		if(i <= x - 1 && j <= y - 2) add_edge(P(i, j), P(i + 1, j + 2));
		if(i <= x - 2 && j <= y - 1) add_edge(P(i, j), P(i + 2, j + 1));
		if(i <= x - 1 && j > 2) add_edge(P(i, j), P(i + 1, j - 2));
		if(i <= x - 2 && j > 1) add_edge(P(i, j), P(i + 2, j - 1));
		if(i > 1 && j <= y - 2) add_edge(P(i, j), P(i - 1, j + 2));
		if(i > 2 && j <= y - 1) add_edge(P(i, j), P(i - 2, j + 1));
		if(i > 1 && j > 2) add_edge(P(i, j), P(i - 1, j - 2));
		if(i > 2 && j > 1) add_edge(P(i, j), P(i - 2, j - 1));
		if(i > 3) add_edge(P(i, j), P(i - 3, j));
		if(j > 3) add_edge(P(i, j), P(i, j - 3));
		if(i <= x - 3) add_edge(P(i, j), P(i + 3, j));
		if(j <= y - 3) add_edge(P(i, j), P(i, j + 3));
	}
	L(i, 1, x) L(j, 1, y) {
		if((i + j) % 2 == 1) continue;
		memset(vis, 0, sizeof(vis));
		res += dfs(P(i, j));
	}
	edge_id = 0;
	L(i, 1, x * y) head[i] = pp[i] = 0;
	return (res << 1);
}
int n, m;// ans, f[N][N];
int main() {
	scanf("%d%d", &n, &m);
	if(n > m) swap(n, m);
	int gg = 0;
	if(n == 1) {
		if(m % 6 == 1 || m % 6 == 5) gg = 1;
		else if(m % 6 == 2 || m % 6 == 4) gg = 2;
		else if(m % 6 == 3) gg = 3;
	}
	else if(n == 2) {
		if(m == 2) gg = 4;
		else if(m == 3 || m == 7) gg = 2;
	}
	else if(n % 2 && m % 2) gg = 1;
	printf("%lld\n", 1ll * n * m - gg);
	// L(i, 1, n) L(j, 1, m) f[i][j] = get(i, j);
	// L(i, 1, n) {
	// 	L(j, 1, m) printf("%3d ", f[i][j]);
	// 	puts("");
	// }
	// L(i, 1, n) L(j, i, m) if(f[i][j] != i * j) cout << i << " " << j << " : " << i * j - f[i][j] << endl;
	return 0;
}