#include <cstdio>
#include <cstring>

typedef unsigned int ui;
const ui Mod = 10007;
const int ML = 205, MS = 305;

inline void Add(ui &x, ui y) { x -= (x += y) >= Mod ? Mod : 0; }

int D;
struct Mat {
	ui A[MS][MS];
	Mat() { memset(A, 0, sizeof A); }
	Mat(int x) {
		memset(A, 0, sizeof A);
		for (int i = 1; i <= D; ++i) A[i][i] = x;
	}
	void operator *= (Mat B) {
		static int C[MS][MS];
		for (int i = 1; i <= D; ++i)
			for (int j = 1; j <= i; ++j)
				C[i][j] = A[i][j], A[i][j] = 0;
		for (int i = 1; i <= D; ++i) {
			for (int k = 1; k <= i; ++k)
				for (int j = 1; j <= k; ++j) {
					A[i][j] += C[i][k] * B.A[k][j];
					if (A[i][j] >= 4194847260) A[i][j] %= Mod;
				}
			for (int j = 1; j <= i; ++j) A[i][j] %= Mod;
		}
	}
} T;

ui Calc(Mat B, int e, int p) {
	Mat A(1); ui v[MS] = {}, t[MS];
	v[1] = 1;
	for (; e; e >>= 1, B *= B) if (e & 1) {
		for (int i = 1; i <= D; ++i) {
			t[i] = 0;
			for (int j = 1; j <= i; ++j) {
				t[i] += B.A[i][j] * v[j];
				if (t[i] >= 4194847260) t[i] %= Mod;
			}
		}
		for (int i = 1; i <= D; ++i) v[i] = t[i] % Mod;
	}
	return v[p];
}

int N, L, G;
char S[ML];
ui f[ML][ML][ML], g[ML], Ans;

int main() {
	scanf("%s%d", S + 1, &N), N += L = strlen(S + 1);
	f[1][L][0] = 1;
	for (int q = L; q >= 1; --q) {
		for (int i = 1; i <= L - q + 1; ++i) {
			int j = i + q - 1, t = S[i] != S[j];
			if (t) {
				for (int x = 0; x < L; ++x)
					Add(f[i + 1][j][x + 1], f[i][j][x]),
					Add(f[i][j - 1][x + 1], f[i][j][x]);
			} else {
				ui *v = i + 2 <= j ? f[i + 1][j - 1] : g;
				for (int x = 0; x < L; ++x)
					Add(v[x], f[i][j][x]);
			}
		}
	}
	G = (L - 1) / 2 + 1, D = L + G + 1;
	for (int i = 1; i <= D; ++i) {
		if (i <= L) {
			if (i > 1) T.A[i][i] = 24;
			T.A[L + G - (L - i) / 2][i] = g[i - 1];
			if (i < L) T.A[i + 1][i] = 1;
		} else if (i < D) {
			T.A[i][i] = 25;
			T.A[i + 1][i] = 1;
		} else T.A[i][i] = 26;
	}
	Ans = (N & 1 ? 26 : 1) * Calc(T, N / 2 + 1, D);
	if (N & 1) {
		for (int i = 1; i <= L; ++i) {
			T.A[L + G - (L - i) / 2][i] = 0;
			for (int j = 1; j <= L; ++j)
				Add(T.A[L + G - (L - i) / 2][i], f[j][j][i - 1]);
		}
		Add(Ans, Calc(T, N / 2 + 1, D - 1));
	}
	printf("%d\n", Ans % Mod);
	return 0;
}