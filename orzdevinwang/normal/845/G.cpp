#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
int n, m, sum[N], ans[66];
int edge_id, head[N];
struct node {
	int to, next, val;
} e[N << 1];
void ins(int x) {
	R(i, 30, 0) if(x & (1 << i)) {
		if(!ans[i]) ans[i] = x;
		x ^= ans[i];
	}
}
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].to = v, e[edge_id].val = val, e[edge_id].next = head[u], head[u] = edge_id;
}
void dfs(int x) {
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(sum[v] != -1) ins(sum[v] ^ (sum[x] ^ e[i].val));
		else sum[v] = (sum[x] ^ e[i].val), dfs(v);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, m) {
		int u, v, val; scanf("%d%d%d", &u, &v, &val);
		add_edge(u, v, val), add_edge(v, u, val);
	}
	memset(sum, -1, sizeof(sum));
	sum[1] = 0;
	dfs(1);
	int res = sum[n];
	R(i, 30, 0) if((res ^ ans[i]) < res) res ^= ans[i];
	printf("%d\n", res);
	return 0;
}