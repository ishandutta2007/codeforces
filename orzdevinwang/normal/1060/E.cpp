#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 5e5 + 7;
const int inf = 1e9 + 7;
int head[N], edge_id;
struct node { int to, next; } e[N << 1];
void add_edge(int u, int v) { ++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id; } 
ll ans;
int n, FN, siz[N], dep[N], rt, rtmax, p[2];
bool vis[N]; 
void findrt(int x, int fa) {
	int maxn = 0; siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa || vis[v]) continue;
		findrt(v, x), siz[x] += siz[v];
		maxn = max(maxn, siz[v]);
	} 
	maxn = max(maxn, FN - siz[x]);
	if(maxn < rtmax) rt = x, rtmax = maxn;
}
ll now = 0;
void George(int x, int fa) {
	siz[x] = 1, now += dep[x];
	if(dep[x] % 2 == 1) p[1] ++;
	else p[0] ++;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa || vis[v]) continue;
		dep[v] = dep[x] + 1;
		George(v, x), siz[x] += siz[v];
	}
}
int f[2];
void dfz(int x) {
	if(FN == 1) return;
	rtmax = inf, findrt(x, -1), vis[rt] = 1;
	f[0] = 1, f[1] = 0;
	for(int i = head[rt]; i; i = e[i].next) {
		int v = e[i].to;
		if(vis[v]) continue;
		p[0] = p[1] = now = 0, dep[v] = 1, George(v, rt);
		ans += now * (FN - siz[v]), ans += (ll) f[0] * p[1] + (ll) f[1] * p[0];
		f[0] += p[0], f[1] += p[1];
	}
	for(int i = head[rt]; i; i = e[i].next) {
		int v = e[i].to;
		if(!vis[v]) FN = siz[v], dfz(v);
	}
} 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		add_edge(u, v), add_edge(v, u);
	}
	FN = n, dfz(1);
	printf("%lld\n", ans / 2);
	return 0;
}