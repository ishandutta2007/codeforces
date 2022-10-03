#include <cstdio>
#include <algorithm>
#include <bitset>

namespace Dinic {
	const int Inf = 0x3f3f3f3f;
	const int MN = 1505, MM = 282385;
	
	int N, S, T;
	int h[MN], iter[MN], nxt[MM * 2], to[MM * 2], w[MM * 2], tot;
	
	inline void Init(int _N) {
		N = _N, tot = 1;
		for (int i = 1; i <= N; ++i) h[i] = 0;
	}
	inline void SetST(int _S, int _T) { S = _S, T = _T; }
	
	inline void ins(int u, int v, int x) { nxt[++tot] = h[u], to[tot] = v, w[tot] = x, h[u] = tot; }
	inline void insw(int u, int v, int w1 = Inf, int w2 = 0) {
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
	
	int Flow(int u, int f) {
		if (u == T) return f;
		int d = 0, s = 0;
		for (int &i = iter[u]; i; i = nxt[i])
			if (w[i] && lv[to[i]] == lv[u] + 1) {
				d = Flow(to[i], std::min(f, w[i]));
				f -= d, s += d;
				w[i] -= d, w[i ^ 1] += d;
				if (!f) break;
			}
		return s;
	}
	
	inline int DoDinic() {
		int Ans = 0;
		while (Lvl()) {
			for (int i = 1; i <= N; ++i) iter[i] = h[i];
			Ans += Flow(S, Inf);
		}
		return Ans;
	}
}
using Dinic::insw;

const int MN = 755, MM = 10000005, MS = 2;

int N, M, Ans;
std::bitset<751> g[MN];

int id[MN];
int nxt[MM][MS], fail[MM], faz[MM], key[MM], cnt;
int que[MM], l, r;
inline void BuildAC() {
	fail[0] = -1;
	que[l = r = 1] = 0;
	while (l <= r) {
		int u = que[l++];
		for (int j = 0; j < MS; ++j) {
			if (nxt[u][j]) {
				fail[nxt[u][j]] = u ? nxt[fail[u]][j] : 0;
				if (!key[nxt[u][j]]) key[nxt[u][j]] = key[fail[nxt[u][j]]];
				que[++r] = nxt[u][j];
			}
			else nxt[u][j] = u ? nxt[fail[u]][j] : 0;
		}
	}
}

int match[MN], tagl[MN], tagr[MN];
void DFS(int u) {
	tagr[u] = 1;
	for (int i = 1; i <= N; ++i)
		if (g[i][u] && !tagl[i])
			tagl[i] = 1, DFS(match[i]);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		static char str[MM];
		scanf("%s", str);
		int now = 0;
		for (char *S = str; *S; ++S) {
			int j = *S - 'a';
			if (!nxt[now][j]) nxt[now][j] = ++cnt, faz[cnt] = now;
			now = nxt[now][j];
		} key[now] = i, id[i] = now;
	}
	BuildAC();
	for (int i = 1; i <= N; ++i)
		for (int x = id[i]; x; x = faz[x]) {
			int z = key[x == id[i] ? fail[x] : x];
			if (z) g[i][z] = 1;
		}
	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			if (g[i][k]) g[i] |= g[k];
	Dinic::Init(N + N + 2), Dinic::SetST(N + N + 1, N + N + 2);
	for (int i = 1; i <= N; ++i)
		insw(0, i, 1), insw(N + i, 0, 1);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (g[i][j]) insw(i, N + j, 1);
	Ans = N - Dinic::DoDinic();
	printf("%d\n", Ans);
	for (int i = 1; i <= N; ++i) if (!Dinic::w[4 * i - 2]) {
		for (int j = Dinic::h[i]; j; j = Dinic::nxt[j])
			if (!Dinic::w[j]) { match[i] = Dinic::to[j] - N; break; }
	}
	for (int i = 1; i <= N; ++i) if (Dinic::w[4 * i]) DFS(i);
	for (int i = 1; i <= N; ++i) if (!tagl[i] && tagr[i]) printf("%d ", i);
	return 0;
}