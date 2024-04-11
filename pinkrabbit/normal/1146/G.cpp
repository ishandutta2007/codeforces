#include <cstdio>
#include <algorithm>

typedef long long LL;
const LL Inf = 0x3f3f3f3f3f3f3f3f;

namespace Dinic {
const int MN = 2555, MM = 7505;

int N, S, T;
int h[MN], iter[MN], nxt[MM * 2], to[MM * 2], tot; LL w[MM * 2];

inline void Init(int _N) {
	N = _N, tot = 1;
	for (int i = 1; i <= N; ++i) h[i] = 0;
}
inline void SetST(int _S, int _T) { S = _S, T = _T; }

inline void ins(int u, int v, LL x) { nxt[++tot] = h[u], to[tot] = v, w[tot] = x, h[u] = tot; }
inline void insw(int u, int v, LL w1, LL w2 = 0) {
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
} // namespace Dinic

int N, H, Q;
LL Ans;

int main() {
	scanf("%d%d%d", &N, &H, &Q);
	Dinic::Init(N * H + Q + 2);
	Dinic::SetST(N * H + Q + 1, N * H + Q + 2);
	Ans = N * H * H;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= H; ++j) {
			Dinic::insw(0, (i - 1) * H + j, 2 * j - 1);
			if (j > 1) Dinic::insw((i - 1) * H + j, (i - 1) * H + j - 1, Inf);
		}
	}
	for (int i = 1; i <= Q; ++i) {
		int l, r, x; LL c;
		scanf("%d%d%d%lld", &l, &r, &x, &c);
		if (++x > H) continue;
		Dinic::insw(N * H + i, 0, c);
		for (int j = l; j <= r; ++j) Dinic::insw((j - 1) * H + x, N * H + i, Inf);
	}
	printf("%lld\n", Ans - Dinic::Dinic());
	return 0;
}

// lg