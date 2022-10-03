#include <cstdio>
#include <algorithm>

namespace MinCostMaxFlows {
	typedef long long LL;
	const LL Inf = 0x3f3f3f3f3f3f3f3f;
	const int MN = 105, MM = 405;
	
	int N, S, T; LL Ans, Cost;
	int h[MN], iter[MN], nxt[MM * 2], to[MM * 2], tot; LL cap[MM * 2], cost[MM * 2];
	
	inline void SetST(int _S, int _T) { S = _S, T = _T; }
	inline void Init(int _N) {
		N = _N, tot = 1;
		for (int i = 1; i <= N; ++i) h[i] = 0;
		SetST(_N - 1, _N);
	}
	
	inline void ins(int u, int v, LL w, LL z) {
		if (tot + 1 >= MM * 2) { puts("Error : too many edges."); return ; }
		nxt[++tot] = h[u], to[tot] = v, cap[tot] = w, cost[tot] = z, h[u] = tot;
	}
	inline void insw(int u, int v, LL w = Inf, LL z = 0) {
		if (!u) u = S; if (!v) v = T;
		ins(u, v, w, z), ins(v, u, 0, -z);
	}
	
	LL dis[MN];
	int que[MN * MM], l, r;
	bool inq[MN], vis[MN];
	
	inline bool SPFA() {
		for (int i = 1; i <= N; ++i) dis[i] = Inf, inq[i] = 0;
		dis[S] = 0, que[l = r = 1] = S, inq[S] = 1;
		while (l <= r) {
			int u = que[l++];
			inq[u] = 0;
			for (int i = h[u]; i; i = nxt[i]) {
				if (!cap[i] || dis[to[i]] <= dis[u] + cost[i]) continue;
				dis[to[i]] = dis[u] + cost[i];
				if (!inq[to[i]]) {
					que[++r] = to[i];
					inq[to[i]] = 1;
				}
			}
		}
		return dis[T] != Inf;
	}
	
	int Flow(int u, LL f) {
		if (u == T) return f;
		vis[u] = 1;
		LL d, s = 0;
		for (int &i = iter[u]; i; i = nxt[i]) {
			if (vis[to[i]] || !cap[i] || dis[to[i]] != dis[u] + cost[i]) continue;
			d = Flow(to[i], std::min(f, cap[i]));
			f -= d, s += d;
			cap[i] -= d, cap[i ^ 1] += d;
			Cost += cost[i] * d;
			if (!f) break;
		}
		vis[u] = 0;
		return s;
	}
	
	inline LL MCMF(int Type) {
		Ans = 0, Cost = 0;
		while (SPFA()) {
			for (int i = 1; i <= N; ++i) iter[i] = h[i];
			Ans += Flow(S, Inf);
		}
		return Type ? Cost : Ans;
	}
}
using MinCostMaxFlows::Inf;
using MinCostMaxFlows::insw;

const int MN = 105;

int N, M, Ans;
int deg[MN];

int main() {
	scanf("%d%d", &N, &M);
	MinCostMaxFlows::Init(N + 2);
	insw(N, 1, Inf);
	for (int i = 1; i <= M; ++i) {
		int u, v, f, c;
		scanf("%d%d%d%d", &u, &v, &c, &f);
		if (f <= c) {
			insw(v, u, f, 1);
			insw(u, v, c - f, 1);
		} else {
			Ans += f - c;
			insw(v, u, f - c, 0);
			insw(v, u, c, 1);
		}
		insw(u, v, Inf, 2);
		deg[u] += f, deg[v] -= f;
	}
	for (int i = 1; i <= N; ++i)
		if (deg[i] > 0) insw(i, 0, deg[i]);
		else insw(0, i, -deg[i]);
	printf("%lld\n", Ans + MinCostMaxFlows::MCMF(1));
	return 0;
}