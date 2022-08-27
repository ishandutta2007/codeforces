// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, m, rt;
int dis[N], maxn[N], minn = 1e9 + 7;
int cmx[N], ccmx[N];
bool vis[N];
int head[N], edge_id;
struct node {
	int to, next, val;
} e[N << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].val = val, e[edge_id].to = v, head[u] = edge_id;
}
void findrt1(int x, int fa) {
	maxn[x] = dis[x];
	if(!vis[x]) maxn[x] = -1e9 - 7;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa) continue;
		dis[v] = dis[x] + e[i].val;
		findrt1(v, x);
		maxn[x] = max(maxn[x], maxn[v]);
		if(maxn[v] > maxn[cmx[x]]) ccmx[x] = cmx[x], cmx[x] = v;
		else if(maxn[v] > maxn[ccmx[x]]) ccmx[x] = v; 
	}
	// cout << "maxn[" << x << "] = " << maxn[x] << "(" << cmx[x] << ")(" << ccmx[x] << ")" << endl;
}
void findrt2(int x, int fa, int mx) {
	// cout << x << " : " << maxn[x] - dis[x] << endl;
	if(vis[x]) mx = max(mx, 0);
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa) continue;
		if(v ^ cmx[x]) findrt2(v, x, max(mx, maxn[cmx[x]] - dis[x]) + e[i].val);
		else findrt2(v, x, max(mx, maxn[ccmx[x]] - dis[x]) + e[i].val);
	}
	mx = max(mx, maxn[x] - dis[x]);
	if(mx < minn) minn = mx, rt = x;
	// cout << x << " : " << mx << endl;
}
int sz[N];
void dfs(int x, int fa) {
	maxn[x] = dis[x], sz[x] = vis[x];
	if(!vis[x]) maxn[x] = - 1e9 - 7;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa) continue;
		dis[v] = dis[x] + e[i].val, dfs(v, x);
		sz[x] += sz[v], maxn[x] = max(maxn[x], maxn[v]);
	}
}
int GG[N];
void fdfs(int x, int fa) {
	int cnt = 0;
	for(int i = head[x]; i; i = e[i].next) if(e[i].to != fa && maxn[e[i].to] == maxn[x]) cnt ++;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa) continue;
		if(maxn[v] == maxn[x] && cnt == 1) GG[v] += GG[x];
		fdfs(v, x);
	}
}
int tot;
struct MMP { int maxdis, id, siz; } p[N];
bool cmp(MMP aa, MMP bb) { return aa.maxdis > bb.maxdis; }
int main() {
	scanf("%d%d", &n, &m);
	fill(maxn, maxn + n + 1, -1e9 - 7);
	L(i, 1, m) {
		int k; scanf("%d", &k);
		vis[k] = 1;
	}
	L(i, 1, n - 1) {
		int u, v, val; 
		scanf("%d%d%d", &u, &v, &val);
		add_edge(u, v, val), add_edge(v, u, val);
	}
	findrt1(1, -1);
	findrt2(1, -1, -1e9 - 7);
	// cout << rt << " : " << minn << endl;
	dis[rt] = 0;
	for(int i = head[rt]; i; i = e[i].next) {
		int v = e[i].to;
		dis[v] = e[i].val, dfs(v, rt), sz[rt] += sz[v];
		++tot, p[tot].id = v, p[tot].maxdis = maxn[v], p[tot].siz = sz[v];
	}
	p[tot + 1].maxdis = -114, p[tot + 2].maxdis = -514;
	sort(p + 1, p + tot + 1, cmp);
	int cnt = 0;
	L(i, 1, tot) if(p[i].maxdis == p[1].maxdis) cnt = i;
	L(i, 1, tot) {
		if(i <= cnt) {
			if(cnt >= 3) continue;
			if(cnt == 1) {
				if(p[2].maxdis == p[3].maxdis) continue;
				GG[p[2].id] += p[i].siz;
			}
			else GG[p[3 - i].id] += p[i].siz; 
		}
		else {
			if(cnt >= 2) continue;
			GG[p[1].id] += p[i].siz;
		}
	}
	if(vis[rt] && cnt == 1) GG[p[1].id] ++;
	for(int i = head[rt]; i; i = e[i].next) fdfs(e[i].to, rt);
	int maxn = 0; cnt = 0;
	L(i, 1, n) if(!vis[i]) maxn = max(maxn, GG[i] + sz[i]);
	L(i, 1, n) if(!vis[i]) cnt += (maxn == GG[i] + sz[i]);
	printf("%d %d\n", maxn, cnt);
	return 0;
}