#include <cstdio>
#include <algorithm>
#include <vector>

#define v first
#define w second
const int MN = 100005;

int N, Q;
std::vector<std::pair<int, int>> G[MN];

struct tr {
	int mxdu, rt, dis[MN], mxd[MN], dep[MN], par[MN][17], son[MN], top[MN], len[MN];
	std::vector<int> V[MN];
	void DFS0(int u, int pr, int t) {
		if (t) {
			dep[u] = dep[par[u][0] = pr] + 1;
			for (int j = 0; 2 << j < dep[u]; ++j)
				par[u][j + 1] = par[par[u][j]][j];
		}
		mxd[u] = dis[u];
		if (!t && dis[mxdu] < dis[u]) mxdu = u;
		for (auto e : G[u]) if (e.v != pr) {
			dis[e.v] = dis[u] + e.w, DFS0(e.v, u, t);
			mxd[u] = std::max(mxd[u], mxd[e.v]);
			if (t && mxd[son[u]] < mxd[e.v]) son[u] = e.v;
		}
	}
	void DFS1(int u, int t) {
		V[top[u] = t].push_back(u);
		if (son[u]) DFS1(son[u], t);
		for (auto e : G[u]) if (e.v != par[u][0] && e.v != son[u])
			DFS1(e.v, e.v), len[e.v] = mxd[e.v] - dis[u];
	}
	int Ans[MN];
	int col[MN], s[MN], c;
	int Init(int x) {
		mxdu = 0, dis[x] = 0, DFS0(x, 0, 0);
		dis[rt = mxdu] = 0, DFS0(rt, 0, 1);
		DFS1(rt, rt), len[rt] = mxd[rt];
		for (int i = 1; i <= N; ++i) if (top[i] == i) s[++c] = i;
		std::sort(s + 1, s + c + 1, [&](int i, int j) { return len[i] > len[j]; });
		for (int i = 1; i <= c; ++i) {
			Ans[i] = Ans[i - 1] + len[s[i]];
			for (int u = s[i]; u; u = son[u]) col[u] = i;
		}
		return rt;
	}
	inline int plan(int x, int y, int *arr) {
		int u = x;
		for (int j = 16; j >= 0; --j)
			if (col[par[u][j]] > y)
				u = par[u][j];
		u = par[u][0];
		return Ans[y] + mxd[x] - arr[u];
	}
	inline int Qur(int x, int y) {
		y = 2 * y - 1;
		if (y >= c) return Ans[c];
		if (col[x] <= y) return Ans[y];
		return std::max(plan(x, y - 1, dis), plan(x, y, mxd));
	}
} t1, t2;

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1, x, y, z; i < N; ++i)
		scanf("%d%d%d", &x, &y, &z),
		G[x].push_back({y, z}),
		G[y].push_back({x, z});
	t2.Init(t1.Init(1));
	int lstans = 0;
	while (Q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x = (x + lstans - 1) % N + 1;
		y = (y + lstans - 1) % N + 1;
		printf("%d\n", lstans = std::max(t1.Qur(x, y), t2.Qur(x, y)));
	}
	return 0;
}