#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define repe for(int i = head[u], v; v = e[i].v; i = e[i].nxt)

using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
int n, b[N], p[N]; ll ans, a[N];
int cnt, head[N];
struct edge { int v, nxt; } e[N*2];
void add(int u, int v) {
	e[++cnt] = (edge){ v, head[u] };
	head[u] = cnt;
}
void dfs1(int u) {
	repe dfs1(v), a[u] += max(a[v], 0LL);
	ans += a[u];
}
void dfs2(int u) {
	repe if(a[v] > 0) dfs2(v);
	p[++cnt] = u;
	repe if(a[v] <= 0) dfs2(v);
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n) {
		scanf("%d", &b[i]);
		if(~b[i]) add(b[i], i);
	}
	cnt = 0;
	rep(i, 1, n) if(!~b[i]) dfs1(i), dfs2(i);
	cout << ans << endl;
	rep(i, 1, n) printf("%d ", p[i]);
	return 0;
}