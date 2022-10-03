#include <cstdio>
#include <algorithm>

namespace DinicFlows {
	typedef long long LL;
	const LL Inf = 0x3f3f3f3f3f3f3f3f;
	const int MN = 20005, MM = 120005;
	
	int N, S, T;
	int h[MN], iter[MN], nxt[MM * 2], to[MM * 2], tot; LL w[MM * 2];
	
	inline void SetST(int _S, int _T) { S = _S, T = _T; }
	inline void Init(int _N) {
		N = _N, tot = 1;
		for (int i = 1; i <= N; ++i) h[i] = 0;
		SetST(_N - 1, _N);
	}
	
	inline void ins(int u, int v, LL x) {
		if (tot + 1 >= MM * 2) { puts("Error : too many edges."); return ; }
		nxt[++tot] = h[u], to[tot] = v, w[tot] = x, h[u] = tot;
	}
	inline void insw(int u, int v, LL w1 = Inf, LL w2 = 0) {
		if (!u) u = S; if (!v) v = T;
		ins(u, v, w1), ins(v, u, w2);
	}
	
	int lv[MN], que[MN], l, r;
	
	inline bool Lvl() {
		for (int i = 1; i <= N; ++i) lv[i] = 0;
		lv[S] = 1;
		que[l = r = 1] = S;
		while (l <= r) {
			int u = que[l++];
			for (int i = h[u]; i; i = nxt[i])
				if (w[i] && !lv[to[i]]) {
					lv[to[i]] = lv[u] + 1;
					que[++r] = to[i];
				}
		}
		return lv[T] != 0;
	}
	
	LL Flow(int u, LL f) {
		if (u == T) return f;
		LL d = 0, s = 0;
		for (int &i = iter[u]; i; i = nxt[i])
			if (w[i] && lv[to[i]] == lv[u] + 1) {
				d = Flow(to[i], std::min(f, w[i]));
				f -= d, s += d;
				w[i] -= d, w[i ^ 1] += d;
				if (!f) break;
			}
		return s;
	}
	
	inline LL Dinic() {
		LL Ans = 0;
		while (Lvl()) {
			for (int i = 1; i <= N; ++i) iter[i] = h[i];
			Ans += Flow(S, Inf);
		}
		return Ans;
	}
}

const int MM = 100005;

int N, M;
int eu[MM], ev[MM], ew[MM], ep[MM];

inline bool check(int pos) {
	DinicFlows::Init(2 * N + 2);
	for (int i = 1; i <= N; ++i)
		DinicFlows::insw(0, i, 1),
		DinicFlows::insw(N + i, 0, 1);
	for (int i = 1; i <= pos; ++i)
		DinicFlows::insw(eu[ep[i]], ev[ep[i]] + N);
	return DinicFlows::Dinic() == N;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i) scanf("%d%d%d", &eu[i], &ev[i], &ew[i]), ep[i] = i;
	std::sort(ep + 1, ep + M + 1, [](int i, int j) { return ew[i] < ew[j]; });
	int l = N, r = M, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) ans = ew[ep[mid]], r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}