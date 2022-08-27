// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define uint unsigned int
using namespace std;
const int N = 2e5 + 7;
int head[N], edge_id;
struct node {
	int to, next;
} e[N << 2];
void add_edge(int u, int v) { 
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
void add(int u, int v) {
	add_edge(u, v), add_edge(v, u);
} 
int col[N];
void dfs(int x) {
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(col[v]) continue;
		col[v] = 3 - col[x], dfs(v);
	}
}
int n, m, lasa[N], lasb[N];
int main() {
	scanf("%d", &n);
	L(i, 1, n) {
		int x, y; scanf("%d%d", &x, &y);
		if(lasa[x]) add(lasa[x], i), lasa[x] = 0;
		else lasa[x] = i;
		if(lasb[y]) add(lasb[y], i), lasb[y] = 0;
		else lasb[y] = i;
	}
	L(i, 1, n) if(!col[i]) col[i] = 1, dfs(i);
	L(i, 1, n) if(col[i] == 1) printf("r"); else printf("b");
	puts("");
	return 0;
}