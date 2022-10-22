#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define repe for(int i = head[u], v; v = e[i].v; i = e[i].nxt) if(v ^ fa)

using namespace std;

const int N = 2e5 + 5;
int n, a[N], g[N], f[N], u, v, cnt, head[N];
struct edge { int v, nxt; } e[N*2];
void add(int u, int v) {
	e[++cnt] = (edge){ v, head[u] };
	head[u] = cnt;
}
void dfs(int u, int fa) {
	f[u] = a[u] ? 1 : -1;
	repe dfs(v, u), f[u] += max(f[v], 0);
}
void Dfs(int u, int fa) {
	g[u] = max(f[fa] - max(f[u], 0) + g[fa], 0);
	repe Dfs(v, u);
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 2, n) scanf("%d%d", &u, &v), add(u, v), add(v, u);
	dfs(1, 0), Dfs(1, 0);
	rep(i, 1, n) printf("%d ", f[i] + g[i]);
	return 0;
}