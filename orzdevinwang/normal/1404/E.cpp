#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
using namespace std;
const int N = 1e6 + 7, M = 300;
const int inf = 1e9 + 7;
int ehd[N], ev[N << 1], ew[N << 1], enx[N << 1], eid = 1; 
void eadd(int u, int v, int val) {
	++eid, ev[eid] = v, enx[eid] = ehd[u], ew[eid] = val, ehd[u] = eid;
}
void add(int u, int v, int val = 1) {
	eadd(u, v, val), eadd(v, u, 0);
}
int dis[N], cur[N], tot, s, t;
bool bfs() {
	fill(dis + 1, dis + tot + 1, inf);
	copy(ehd + 1, ehd + tot + 1, cur + 1);
	queue<int> q;
	q.push(s), dis[s] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = ehd[u]; i; i = enx[i]) 
			if(ew[i] && dis[ev[i]] > dis[u] + 1) dis[ev[i]] = dis[u] + 1, q.push(ev[i]);
	}
	return dis[t] < inf;
}
int dfs(int x, int flow) {
	if(x == t) return flow;
	int sv = flow;
	for(int i = cur[x]; i; i = enx[i]) {
		cur[x] = i;
		if(!ew[i] || dis[ev[i]] != dis[x] + 1) continue;
		int fl = dfs(ev[i], min(ew[i], flow));
		ew[i] -= fl, ew[i ^ 1] += fl, flow -= fl;
		if(!flow) break;
	}
	return sv - flow;
}
int dinic() {
	int res = 0;
	while(bfs()) res += dfs(s, inf);
	return res;
}
int n, m, ans;
char mp[M][M];
#define P(op, i, j) ((op) * n * m + ((i) - 1) * m + (j))
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m, tot = n * m * 2, s = ++tot, t = ++tot;
	L(i, 1, n) cin >> (mp[i] + 1); 
	L(i, 1, n) L(j, 1, m) if(mp[i][j] == '#') ans ++;
	L(i, 1, n) L(j, 1, m) if(mp[i][j] == '#' && mp[i + 1][j] == '#') add(s, P(0, i, j)), ans --;
	L(i, 1, n) L(j, 1, m) if(mp[i][j] == '#' && mp[i][j + 1] == '#') add(P(1, i, j), t), ans --;
	L(i, 1, n) L(j, 1, m) if(mp[i][j] == '#') {
		if(mp[i + 1][j] == '#' && mp[i][j + 1] == '#') add(P(0, i, j), P(1, i, j));
		if(mp[i + 1][j] == '#' && mp[i][j - 1] == '#') add(P(0, i, j), P(1, i, j - 1));
		if(mp[i - 1][j] == '#' && mp[i][j + 1] == '#') add(P(0, i - 1, j), P(1, i, j));
		if(mp[i - 1][j] == '#' && mp[i][j - 1] == '#') add(P(0, i - 1, j), P(1, i, j - 1));
	}
	cout << ans + dinic() << "\n";
	return 0;
}