#include <cstdio>
#include <algorithm>

typedef long long LL;
const LL Inf = 0x7fffffffffffffff;

namespace Dinic {
	const int MN = 205, MM = 10005;
	
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
}

const int MM = 51, MS = 105;

int M, sx[MM], sy[MM], tx[MM], ty[MM];
int dx[MS], dy[MS], cx, cy;
int V[MS][MS];

int main() {
	scanf("%*d%d", &M);
	for (int i = 1; i <= M; ++i)
		scanf("%d%d%d%d", &sx[i], &sy[i], &tx[i], &ty[i]),
		dx[++cx] = sx[i], dx[++cx] = tx[i] + 1,
		dy[++cy] = sy[i], dy[++cy] = ty[i] + 1;
	std::sort(dx + 1, dx + cx + 1);
	std::sort(dy + 1, dy + cy + 1);
	cx = std::unique(dx + 1, dx + cx + 1) - dx - 1;
	cy = std::unique(dy + 1, dy + cy + 1) - dy - 1;
	Dinic::Init(cx + cy), Dinic::SetST(cx + cy - 1, cx + cy);
	for (int j = 1; j < cx; ++j) Dinic::insw(0, j, dx[j + 1] - dx[j]);
	for (int j = 1; j < cy; ++j) Dinic::insw(cx - 1 + j, 0, dy[j + 1] - dy[j]);
	for (int i = 1; i <= M; ++i) {
		int lx, rx, ly, ry;
		lx = std::lower_bound(dx + 1, dx + cx + 1, sx[i]) - dx;
		rx = std::lower_bound(dx + 1, dx + cx + 1, tx[i] + 1) - dx - 1;
		ly = std::lower_bound(dy + 1, dy + cy + 1, sy[i]) - dy;
		ry = std::lower_bound(dy + 1, dy + cy + 1, ty[i] + 1) - dy - 1;
		for (int j = lx; j <= rx; ++j)
			for (int k = ly; k <= ry; ++k)
				V[j][k] = 1;
	}
	for (int j = 1; j < cx; ++j)
		for (int k = 1; k < cy; ++k)
			if (V[j][k]) Dinic::insw(j, cx - 1 + k, Inf);
	printf("%lld\n", Dinic::Dinic());
	return 0;
}