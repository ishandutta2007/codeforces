// luogu-judger-enable-o2
#include <cstdio>
#include <vector>

#define csi const int
typedef long long LL;
csi Mod = 1000000007;
csi MN = 200005, MP = 17995;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

bool ip[MN];
int p[MP], pc;
int Inv[MN], phi[MN], f[MN];
std::vector<int> F[MN];
inline void Init(csi &N) {
	Inv[0] = 1;
	for (int i = 1; i <= N; ++i)
		Inv[i] = (LL)Inv[i - 1] * i % Mod;
	int iFac = qPow(Inv[N], Mod - 2);
	for (int i = N; i >= 1; --i)
		Inv[i] = (LL)iFac * Inv[i - 1] % Mod,
		iFac = (LL)iFac * i % Mod;
	phi[1] = f[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (!ip[i]) p[++pc] = i, phi[i] = i - 1, f[i] = Inv[i - 1];
		for (int j = 1; j <= pc; ++j) {
			csi &k = p[j] * i;
			if (k > N) break;
			ip[k] = 1;
			if (i % p[j])
				phi[k] = phi[i] * (p[j] - 1),
				f[k] = (LL)f[i] * f[p[j]] % Mod;
			else { phi[k] = phi[i] * p[j]; break; }
		}
	}
	for (int i = 1; i <= N; ++i) if (f[i])
		for (int j = i; j <= N; j += i)
			F[j].push_back(i);
}

int N, A[MN], Ans;
std::vector<int> G[MN];
int dep[MN], dfn[MN], idf[MN], dfc;
int ieu[MN * 2], leu[MN], reu[MN], euc;
void DFS(csi &u, csi &fz) {
	dep[u] = dep[fz] + 1;
	idf[dfn[u] = ++dfc] = u;
	ieu[leu[u] = ++euc] = u;
	for (auto v : G[u]) if (v != fz)
		DFS(v, u), ieu[++euc] = u;
	reu[u] = euc;
}
inline int ckdep(csi &i, csi &j) {
	return dep[i] < dep[j] ? i : j;
}
int lg[MN * 2], ST[19][MN * 2];
void _ST() {
	lg[0] = -1;
	for (int i = 1; i <= euc; ++i) {
		lg[i] = lg[i >> 1] + 1;
		ST[0][i] = ieu[i];
	}
	for (int j = 0; j < lg[euc]; ++j)
		for (int i = 2 << j; i <= euc; ++i)
			ST[j + 1][i] = ckdep(ST[j][i - (1 << j)], ST[j][i]);
}
inline int rmq(csi &l, csi &r) {
	csi &g = lg[r - l + 1];
	return ckdep(ST[g][l + (1 << g) - 1], ST[g][r]);
}
inline int lca(csi &u, csi &v) {
	if (reu[u] < leu[v]) return rmq(reu[u], leu[v]);
	if (reu[v] < leu[u]) return rmq(reu[v], leu[u]);
	return ckdep(u, v);
}

std::vector<int> V[MN];
int stk[MN], tp, st[MN], t;
std::vector<int> T[MN];
int val[MN];
inline void AddP(csi &x, csi &y) {
	if (y) T[x].push_back(y), val[y] = dep[y] - dep[x];
}
int it[MN], sphi[MN], Sum;
inline void DP(csi &u) {
	sphi[u] = it[u] ? phi[A[u]] : 0;
	for (auto v : T[u]) {
		DP(v);
		sphi[u] += sphi[v];
		if (sphi[u] >= Mod) sphi[u] -= Mod;
	}
	Sum = (Sum - (LL)sphi[u] * sphi[u] % Mod * val[u]) % Mod;
}
void vtree() {
	for (int id = 1; id <= N; ++id) {
		int u = idf[id], k = A[u];
		for (auto i : F[k]) V[i].push_back(u);
	}
	for (int i = 1; i <= N; ++i) {
		if (!f[i]) continue;
		int sz = V[i].size(), x;
		int S1 = 0, S2 = 0;
		for (int j = 0; j < sz; ++j) {
			int u = V[i][j];
			it[u] = 1;
			st[++t] = u;
			S1 += phi[A[u]];
			if (S1 >= Mod) S1 -= Mod;
			S2 = (S2 + (LL)phi[A[u]] * dep[u]) % Mod;
			if (tp) {
				csi &l = lca(stk[tp], u), &dl = dep[l];
				for (x = 0; tp && dep[stk[tp]] > dl; x = stk[tp--])
					AddP(stk[tp], x);
				if (stk[tp] != l) stk[++tp] = l, st[++t] = l;
				AddP(stk[tp], x);
				stk[++tp] = u;
			}
			else stk[++tp] = u;
		}
		for (x = 0; tp; x = stk[tp--]) AddP(stk[tp], x);
		val[x] = dep[x];
		Sum = (LL)S1 * S2 % Mod;
		DP(x);
		Ans = (Ans + (LL)f[i] * (Sum + Mod)) % Mod;
		while (t) it[st[t]] = 0, T[st[t--]].clear();
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	Init(N);
	for (int i = 1, x, y; i < N; ++i)
		scanf("%d%d", &x, &y),
		G[x].push_back(y),
		G[y].push_back(x);
	DFS(1, 0);
	_ST();
	vtree();
	printf("%lld\n", (LL)Ans * qPow((LL)N * (N - 1) / 2 % Mod, Mod - 2) % Mod);
	return 0;
}

// luogu