#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db long double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 5e5 + 7;
const int inf = 1e9 + 7;
int n, k, a[N], nxt[N], f[N], deg[N], dis[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int head[N], edge_id;
struct node {
	int to, next; 
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
int ans[N], tot;
int main() {
	scanf("%d%d", &n, &k);
	L(i, 1, n) f[i] = i;
	L(i, 1, n) scanf("%d", &a[i]);
	L(i, 1, k) {
		int u, v; scanf("%d%d", &u, &v);
		if(find(u) == find(v)) return puts("0"), 0;
		f[find(v)] = find(u), nxt[u] = v;
	}
	L(i, 1, n) if(a[i] && find(i) != find(a[i])) add_edge(find(a[i]), find(i)), deg[find(i)] ++;
	queue<int> q;
	L(i, 1, n) if(f[i] == i && deg[i] == 0) q.push(i);
	while(!q.empty()) {
		int u = q.front(), now = u, cnt = 0;
		q.pop();
		while(now) ans[++tot] = now, dis[now] = ++cnt, now = nxt[now]; 
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			deg[v] --;
			if(deg[v] == 0) q.push(v);
		}
	}
	L(i, 1, n) if(find(a[i]) == find(i) && dis[a[i]] > dis[i]) return puts("0"), 0;
	if(tot != n) puts("0");
	else L(i, 1, n) printf("%d%s", ans[i], i == n ? "\n" : " ");
	return 0;
}