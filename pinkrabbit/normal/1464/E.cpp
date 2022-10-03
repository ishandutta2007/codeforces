#include <cstdio>
#include <vector>

typedef long long LL;
const int Mod = 998244353;
const int MN = 100005;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}
inline int gInv(int x) { return qPow(x, Mod - 2); }

int N, M, deg[MN], SG[MN];
std::vector<int> G[MN];

void Topo() {
	static int que[MN], buk[MN];
	int l = 1, r = 0;
	for (int i = 1; i <= N; ++i) if (!deg[i]) que[++r] = i;
	while (l <= r) {
		int u = que[l++];
		for (int v : G[u])
			if (!--deg[v]) que[++r] = v;
	}
	for (int i = N; i >= 1; --i) {
		int u = que[i];
		for (int v : G[u]) buk[SG[v]] = 1;
		while (buk[SG[u]]) ++SG[u];
		for (int v : G[u]) buk[SG[v]] = 0;
	}
}

int w[1 << 10];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1, x, y; i <= M; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		++deg[y];
	}
	Topo();
	for (int i = 1; i <= N; ++i) ++w[SG[i]];
	for (int j = 0; j < 10; ++j)
		for (int i = 0; i < 1 << 10; ++i) if (~i >> j & 1) {
			int x = w[i], y = w[i ^ 1 << j];
			w[i] = (x + y) % Mod;
			w[i ^ 1 << j] = (x - y + Mod) % Mod;
		}
	for (int i = 0; i < 1 << 10; ++i) w[i] = gInv((N + 1 - w[i] + Mod) % Mod);
	for (int j = 0; j < 10; ++j)
		for (int i = 0; i < 1 << 10; ++i) if (~i >> j & 1) {
			int x = w[i], y = w[i ^ 1 << j];
			w[i] = (x + y) % Mod;
			w[i ^ 1 << j] = (x - y + Mod) % Mod;
		}
	printf("%lld\n", (1 - (LL)w[0] * gInv(1 << 10) % Mod + Mod) % Mod);
	return 0;
}