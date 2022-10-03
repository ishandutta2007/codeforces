#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

typedef long long LL;
typedef double re;
const int MN = 200005;

int N, wgh[MN];
std::vector<std::pair<int, int>> G[MN];

int Ansu; re Ans, now;

int vis[MN], siz[MN], Rt, tsz, rsz;
void GetRt(int u, int fz) {
	siz[u] = 1;
	int mxs = 0;
	for (auto e : G[u]) {
		int v = e.first;
		if (v == fz) continue;
		if (vis[v]) continue;
		GetRt(v, u);
		siz[u] += siz[v];
		mxs = std::max(mxs, siz[v]);
	}
	mxs = std::max(mxs, tsz - siz[u]);
	if (mxs < rsz) Rt = u, rsz = mxs;
}
re DFS(int u, int fz, LL dis) {
	re sum = wgh[u] * sqrt(dis);
	now += (re)wgh[u] * dis * sqrt(dis);
	for (auto e : G[u]) {
		int v = e.first;
		int l = e.second;
		if (v == fz) continue;
		sum += DFS(v, u, dis + l);
	}
	return sum;
}
void Solve(int u) {
	static re vals[MN]; int tp = 0;
	re sval = 0; now = 0;
	for (auto e : G[u]) {
		int v = e.first;
		int l = e.second;
		vals[++tp] = DFS(v, u, l);
		sval += vals[tp];
	}
	if (now < Ans) Ans = now, Ansu = u;
	vis[u] = 1;
	tp = 0;
	for (auto e : G[u]) {
		int v = e.first;
		if (sval - 2 * vals[++tp] < 0) {
			if (!vis[v]) {
				rsz = tsz = siz[v] < siz[u] ? siz[v] : tsz - siz[u];
				GetRt(v, u), Solve(Rt);
			}
			return ;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &wgh[i]);
	for (int i = 1, x, y, z; i < N; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		G[x].push_back({y, z});
		G[y].push_back({x, z});
	}
	Ans = 1e99;
	rsz = tsz = N, GetRt(1, 0), Solve(Rt);
	printf("%d %.15lf\n", Ansu, Ans);
	return 0;
}