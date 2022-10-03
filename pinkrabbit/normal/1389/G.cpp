#include <cstdio>
#include <vector>

typedef long long LL;
const int MN = 300005, MM = 300005;

int N, M, K, keyo[MN], exe[MM], bel[MN];
LL A[MN], W[MN];
std::vector<int> G[MN];

int cnt, key[MN]; LL wu[MN], Swu;
std::vector<std::pair<int, LL>> T[MN];

int dfn[MN], low[MN], stk[MN], dfc, tp;
void Tarjan(int u, int pe) {
	low[u] = dfn[u] = ++dfc;
	stk[++tp] = u;
	for (auto e : G[u]) {
		int v = exe[e] ^ u;
		if (!dfn[v]) Tarjan(v, e), low[u] = std::min(low[u], low[v]);
		else if (e != pe) low[u] = std::min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++cnt;
		for (int x = 0; x != u; --tp) {
			x = stk[tp];
			bel[x] = cnt;
			key[cnt] += keyo[x];
			wu[cnt] += A[x];
			for (int e : G[x]) {
				int v = exe[e] ^ x;
				if (bel[v] && bel[v] < cnt) {
					int j = bel[v];
					T[cnt].push_back({j, W[e]});
					T[j].push_back({cnt, W[e]});
				}
			}
		}
	}
}

int skey[MN]; LL swu[MN], f[MN];
void DFS0(int u, int p) {
	swu[u] = f[u] = wu[u], skey[u] = key[u];
	for (auto e : T[u]) {
		int v = e.first;
		LL w = e.second;
		if (v == p) continue;
		DFS0(v, u);
		swu[u] += swu[v];
		skey[u] += skey[v];
		f[u] += skey[v] ? std::max(f[v] - w, 0ll) : swu[v];
	}
}

int wtf[MN];
LL g[MN];
void DFS1(int u, int p) {
	LL tg = g[u];
	for (auto e : T[u]) {
		int v = e.first;
		LL w = e.second;
		if (v == p) continue;
		tg += skey[v] ? std::max(f[v] - w, 0ll) : swu[v];
	}
	for (auto e : T[u]) {
		int v = e.first;
		LL w = e.second;
		if (v == p) continue;
		LL dp = tg - (skey[v] ? std::max(f[v] - w, 0ll) : swu[v]);
		g[v] = wu[v] + (K - skey[v] ? std::max(dp - w, 0ll) : Swu - swu[v]);
		if (!skey[v]) wtf[v] = wtf[u] ? wtf[u] : u;
		DFS1(v, u);
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1, x; i <= K; ++i) scanf("%d", &x), keyo[x] = 1;
	for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]), Swu += A[i];
	for (int i = 1; i <= M; ++i) scanf("%lld", &W[i]);
	for (int i = 1, x, y; i <= M; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(i);
		G[y].push_back(i);
		exe[i] = x ^ y;
	}
	Tarjan(1, 0);
	int Root = 0;
	for (int i = 1; i <= cnt; ++i) if (key[i]) { Root = i; break; }
	DFS0(Root, 0);
	g[Root] = wu[Root];
	DFS1(Root, 0);
	for (int i = 1; i <= cnt; ++i) if (!wtf[i]) wtf[i] = i;
	for (int i = 1; i <= N; ++i) {
		int z = wtf[bel[i]];
		printf("%lld%c", f[z] + g[z] - wu[z], " \n"[i == N]);
	}
	return 0;
}