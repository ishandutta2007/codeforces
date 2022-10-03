#include <cstdio>
#include <algorithm>

namespace Dinic {
	typedef long long LL;
	const LL Inf = 0x3f3f3f3f3f3f3f3f;
	const int MN = 200010, MM = 500010;
	
	int N, S, T;
	int h[MN], iter[MN], nxt[MM * 2], to[MM * 2], tot; LL w[MM * 2];
	
	inline void Init(int _N) {
		N = _N, tot = 1;
		for (int i = 1; i <= N; ++i) h[i] = 0;
	}
	inline void SetST(int _S, int _T) { S = _S, T = _T; }
	
	inline void ins(int u, int v, LL x) { nxt[++tot] = h[u], to[tot] = v, w[tot] = x, h[u] = tot; }
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

typedef long long LL;
const int MN = 100005;

int N, M, rr, bb, x[MN], y[MN];
int dx[MN], dy[MN], cx, cy;
int cntx[MN], cnty[MN], difx[MN], dify[MN];
int lbx[MN], rbx[MN], lby[MN], rby[MN];
LL Slbx, Slby, Ans;

int main() {
	scanf("%d%d%d%d", &N, &M, &rr, &bb);
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		dx[i] = x[i], dy[i] = y[i];
	}
	std::sort(dx + 1, dx + N + 1), cx = std::unique(dx + 1, dx + N + 1) - dx - 1;
	std::sort(dy + 1, dy + N + 1), cy = std::unique(dy + 1, dy + N + 1) - dy - 1;
	for (int i = 1; i <= N; ++i) {
		x[i] = std::lower_bound(dx + 1, dx + cx + 1, x[i]) - dx;
		y[i] = std::lower_bound(dy + 1, dy + cy + 1, y[i]) - dy;
		++cntx[x[i]], ++cnty[y[i]];
	}
	for (int i = 1; i <= cx; ++i) difx[i] = cntx[i];
	for (int i = 1; i <= cy; ++i) dify[i] = cnty[i];
	for (int i = 1; i <= M; ++i) {
		int op, pos, npos, val;
		scanf("%d%d%d", &op, &pos, &val);
		if (op == 1) {
			npos = std::lower_bound(dx + 1, dx + cx + 1, pos) - dx;
			if (dx[npos] == pos) difx[npos] = std::min(difx[npos], val);
		} else {
			npos = std::lower_bound(dy + 1, dy + cy + 1, pos) - dy;
			if (dy[npos] == pos) dify[npos] = std::min(dify[npos], val);
		}
	}
	Dinic::Init(cx + cy + 4);
	Dinic::SetST(cx + cy + 1, cx + cy + 2);
	for (int i = 1; i <= N; ++i) Dinic::insw(x[i], cx + y[i], 1);
	for (int i = 1; i <= cx; ++i) {
		lbx[i] = (cntx[i] - difx[i] + 1) / 2;
		rbx[i] = (cntx[i] + difx[i]) / 2;
		if (rbx[i] < lbx[i]) return puts("-1"), 0;
		Dinic::insw(0, i, rbx[i] - lbx[i]);
		Slbx += lbx[i];
	}
	for (int i = 1; i <= cy; ++i) {
		lby[i] = (cnty[i] - dify[i] + 1) / 2;
		rby[i] = (cnty[i] + dify[i]) / 2;
		if (rby[i] < lby[i]) return puts("-1"), 0;
		Dinic::insw(cx + i, 0, rby[i] - lby[i]);
		Slby += lby[i];
	}
	Dinic::insw(Dinic::T, Dinic::S);
	Dinic::SetST(cx + cy + 3, cx + cy + 4);
	Dinic::insw(cx + cy + 1, 0, Slbx);
	Dinic::insw(0, cx + cy + 2, Slby);
	for (int i = 1; i <= cx; ++i) Dinic::insw(0, i, lbx[i]);
	for (int i = 1; i <= cy; ++i) Dinic::insw(cx + i, 0, lby[i]);
	Ans = Dinic::Dinic();
	if (Ans != Slbx + Slby) return puts("-1"), 0;
	Dinic::SetST(cx + cy + 1, cx + cy + 2);
	Ans = Dinic::Dinic();
	printf("%lld\n", Ans * std::min(rr, bb) + (N - Ans) * std::max(rr, bb));
	for (int i = 1; i <= N; ++i) putchar("rb"[(rr > bb) ^ Dinic::w[i * 2]]);
	return 0;
}