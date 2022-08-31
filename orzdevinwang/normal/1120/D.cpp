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
int n, head[N], w[N], edge_id;
struct node {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
// dpa : 
// dpb : 
int fg[N], chs[N], tot;
ll dpa[N], dpb[N], g[N];
int Ans[N], ps[N], atot, hehe[N];
void dfs(int x, int fa) {
	if(!e[head[x]].next && x ^ 1) {
		dpa[x] = w[x];
		dpb[x] = 0;
		return;
	}
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v, x);
		dpa[x] += dpa[v];
	}
	tot = 0;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa) continue;
		++tot, g[tot] = dpa[v] - dpb[v];
	}
	sort(g + 1, g + tot + 1), reverse(g + 1, g + tot + 1);
	dpb[x] = dpa[x] - g[1], chs[x] = g[1], hehe[x] = (tot > 1 && g[1] == g[2]), fg[x] = 1;
	if(dpa[x] == dpb[x] + w[x]) fg[x] = 3;
	if(dpa[x] > dpb[x] + w[x]) fg[x] = 2, dpa[x] = dpb[x] + w[x];
}
int dd[N];
void Print(int x, int fa, int flag) {
	if(!e[head[x]].next && x ^ 1) {
		if(flag & 1) Ans[++atot] = x;
		return;
	}
	// 
	if((flag & 1) && (fg[x] & 2)) Ans[++atot] = x;
	if((flag & 2) || ((flag & 1) && (fg[x] & 2))) {
		// 
		for(int i = head[x]; i; i = e[i].next) {
			int v = e[i].to; if(v == fa) continue;
			if(dpa[v] - dpb[v] == chs[x]) {
				if(hehe[x]) dd[v] = 3;
				else dd[v] = 2;
			}
			else dd[v] = 1;
		}
	}
	if((flag & 1) && (fg[x] & 1)) {
		for(int i = head[x]; i; i = e[i].next) {
			int v = e[i].to; if(v == fa) continue;
			dd[v] |= 1;
		}
	}
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to; if(v == fa) continue;
		Print(v, x, dd[v]);
	}
}
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &w[i]);
	L(i, 1, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		add_edge(u, v), add_edge(v, u);
	}
	dfs(1, -1);
	printf("%lld ", dpa[1]);
	Print(1, -1, 1); sort(Ans + 1, Ans + atot + 1);
	printf("%d\n", atot);
	L(i, 1, atot) printf("%d ", Ans[i]);
	puts("");
	return 0;
}