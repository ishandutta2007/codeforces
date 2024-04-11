#include <cstdio>
#include <vector>

typedef long long LL;
const int Mod = 998244353;
const int MN = 150005;

inline int gInv(int b) {
	int a = 1, e = Mod - 2;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

int N, Q;
std::vector<int> G[MN];

int faz[MN], dep[MN], siz[MN], son[MN], top[MN], ldf[MN], rdf[MN], dfc;
void DFS0(int u, int fz) {
	dep[u] = dep[faz[u] = fz] + 1, siz[u] = 1;
	for (auto v : G[u]) if (v != fz) {
		DFS0(v, u);
		siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
}
void DFS1(int u, int tp) {
	top[u] = tp, ldf[u] = ++dfc;
	if (son[u]) DFS1(son[u], tp);
	for (auto v : G[u]) if (v != faz[u] && v != son[u]) DFS1(v, v);
	rdf[u] = dfc;
}

int B[MN];
inline void Add(int i, int x) { for (; i <= N; i += i & -i) B[i] -= (B[i] += x) >= Mod ? Mod : 0; }
inline int Qur(int i) { int A = 0; for (; i; i -= i & -i) A -= (A += B[i]) >= Mod ? Mod : 0; return A; }

int tag[MN], InvN, totSum;

int main() {
	scanf("%d%d", &N, &Q), InvN = gInv(N);
	for (int i = 1; i < N; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS0(1, 0), DFS1(1, 0);
	while (Q--) {
		int op, u, x;
		scanf("%d%d", &op, &u);
		if (op == 1) {
			scanf("%d", &x);
			totSum = (totSum + (LL)x * siz[u] % Mod * InvN) % Mod;
			int val = (LL)x * (N - siz[u]) % Mod * InvN % Mod;
			Add(ldf[u], val);
			Add(rdf[u] + 1, Mod - val);
			tag[u] -= x; if (tag[u] < 0) tag[u] += Mod;
			if (son[u]) {
				int val2 = (LL)(Mod - x) * siz[son[u]] % Mod * InvN % Mod;
				Add(ldf[son[u]], val2);
				Add(rdf[son[u]] + 1, Mod - val2);
			}
		} else {
			int Ans = Qur(ldf[u]);
			while (faz[top[u]]) {
				u = top[u];
				Ans = (Ans + (LL)tag[faz[u]] * siz[u] % Mod * InvN) % Mod;
				u = faz[u];
			}
			printf("%d\n", (totSum + Ans) % Mod);
		}
	}
	return 0;
}