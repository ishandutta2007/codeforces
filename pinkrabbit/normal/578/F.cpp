#include <cstdio>
#include <algorithm>

typedef long long LL;
int Mod;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

const int MN = 105, MS = 405;

int N, M, Ans;
char fk[MN][MN];
int fa[MN * MN], col[MN * MN]; int ff(int x) { return fa[x] ? fa[x] = ff(fa[x]) : x; }
inline int Id(int x, int y) { return (x - 1) * (M + 1) + y; }
inline int Add(int x, int y) { if ((x = ff(x)) == (y = ff(y))) return 0; return fa[y] = x, 1; }
int Z, A[MS][MS];
inline void C(int x, int y) { ++A[x][x], ++A[y][y], --A[x][y], --A[y][x]; }

inline int Gauss() {
	--Z;
	int Num = 1;
	for (int i = 1; i <= Z; ++i) {
		int o = 0;
		for (int j = i; j <= Z; ++j) if (A[j][i]) { o = j; break; }
		if (!o) return 0;
		if (o != i) {
			Num = -Num;
			for (int k = i; k <= Z; ++k) std::swap(A[i][k], A[o][k]);
		}
		Num = (LL)Num * A[i][i] % Mod;
		int c = qPow(A[i][i], Mod - 2);
		for (int j = Z; j > i; --j) {
			int d = (LL)A[j][i] * c % Mod;
			for (int k = i; k <= Z; ++k) A[j][k] = (A[j][k] - (LL)A[i][k] * d) % Mod;
		}
	}
	return Num;
}

int main() {
	scanf("%d%d%d", &N, &M, &Mod);
	for (int i = 1; i <= N; ++i) {
		scanf("%s", fk[i] + 1);
		for (int j = 1; j <= M; ++j) {
			if (fk[i][j] == '\\' && !Add(Id(i, j), Id(i + 1, j + 1))) return puts("0"), 0;
			if (fk[i][j] == '/' && !Add(Id(i, j + 1), Id(i + 1, j))) return puts("0"), 0;
		}
	}
	for (int o = 0; o < 2; ++o) {
		Z = 0;
		for (int i = 1; i <= N + 1; ++i)
			for (int j = 1; j <= M + 1; ++j)
				if ((i ^ j ^ o) & 1 && ff(Id(i, j)) == Id(i, j))
					col[Id(i, j)] = ++Z;
		for (int i = 1; i <= Z; ++i)
			for (int j = 1; j <= Z; ++j)
				A[i][j] = 0;
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= M; ++j)
				if (fk[i][j] == '*') {
					if ((i ^ j ^ o) & 1) C(col[ff(Id(i, j))], col[ff(Id(i + 1, j + 1))]);
					else C(col[ff(Id(i, j + 1))], col[ff(Id(i + 1, j))]);
				}
		Ans = (Ans + Gauss()) % Mod;
	}
	printf("%d\n", (Ans + Mod) % Mod);
	return 0;
}