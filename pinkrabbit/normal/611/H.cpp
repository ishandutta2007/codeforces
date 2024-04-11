#include <cstdio>
#include <cstring>
#include <algorithm>

const int MM = 7;

int N, M, Id[MM], B[MM], J[MM][MM];

inline void Init() {
	char s[7]; int u, v;
	scanf("%d", &N);
	for (int x = 1; x <= N; x *= 10) Id[++M] = x;
	for (int i = 1; i < M; ++i) B[i] = Id[i + 1] - Id[i] - 1;
	B[M] = N - Id[M];
	for (int i = 1; i < N; ++i) {
		scanf("%s", s), u = strlen(s);
		scanf("%s", s), v = strlen(s);
		if (u > v) std::swap(u, v);
		++J[u][v];
	}
}

namespace Dinic {
	typedef long long LL;
	const LL Inf = 0x3f3f3f3f3f3f3f3f;
	const int MN = 35, MM = 155;
	
	int N, S, T;
	int h[MN], iter[MN], nxt[MM * 2], to[MM * 2], tot; LL w[MM * 2];
	
	inline void SetST(int, int);
	inline void Init(int _N) {
		N = _N, tot = 1;
		for (int i = 1; i <= N; ++i) h[i] = 0;
		SetST(_N - 1, _N);
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

int prufer[MM];

int Solve() {
	static int E[MM][MM], deg[MM], EU[MM], EV[MM], xv[30], Id2[MM]; int EC = 0;
	memcpy(E, J, sizeof J);
	for (int i = 1; i <= M; ++i) deg[i] = 0;
	for (int i = 1; i <= M - 2; ++i) ++deg[prufer[i]];
	prufer[M - 1] = M;
	auto Edg = [&](int u, int v) -> int {
		if (u > v) std::swap(u, v);
		EU[++EC] = u, EV[EC] = v;
		if (!E[u][v]) return 0;
		return --E[u][v], 1;
	};
	for (int i = 1, j = 1; i < M; ++i, ++j) {
		while (deg[j]) ++j;
		if (!Edg(prufer[i], j)) return 0;
		for (; i < M && !--deg[prufer[i]] && prufer[i] < j; ++i)
			if (!Edg(prufer[i], prufer[i + 1])) return 0;
	}
	Dinic::Init(M + M * (M + 1) / 2 + 2);
	for (int i = 1; i <= M; ++i) Dinic::insw(i, 0, B[i]);
	int cnt = M;
	for (int i = 1; i <= M; ++i) {
		for (int j = i; j <= M; ++j) {
			Dinic::insw(0, ++cnt, E[i][j]);
			xv[cnt] = i ^ j;
			Dinic::insw(cnt, i);
			Dinic::insw(cnt, j);
		}
	}
	if (Dinic::Dinic() != N - M) return 0;
	for (int i = 1; i < M; ++i) printf("%d %d\n", Id[EU[i]], Id[EV[i]]);
	for (int i = 1; i <= M; ++i) {
		Id2[i] = Id[i];
		for (int j = Dinic::h[i]; j; j = Dinic::nxt[j]) {
			if (Dinic::to[j] == Dinic::T) continue;
			int k = i ^ xv[Dinic::to[j]];
			while (Dinic::w[j]--) printf("%d %d\n", Id[k], ++Id2[i]);
		}
	}
	return 1;
}

int DFS(int st) {
	if (st == M - 1) return Solve();
	for (int i = 1; i <= M; ++i) {
		prufer[st] = i;
		if (DFS(st + 1)) return 1;
	}
	return 0;
}

int main() {
	Init();
	if (M == 1) {
		for (int i = 1; i < N; ++i)
			printf("%d %d\n", i, i + 1);
		return 0;
	}
	if (!DFS(1)) puts("-1");
	return 0;
}