#include <cstdio>
#include <cstring>
#include <algorithm>

#define uF(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i >= (b); --i)

const int Mod = 1000000007;
const int ML = 2005;

inline void Add(int &x, int y) { x -= (x += y) >= Mod ? Mod : 0; }

int N, M, Ans;
char S[2][ML], T[ML];

int LCP1[2][ML][ML], LCP2[2][ML][ML];
int LCS1[2][ML][ML], LCS2[2][ML][ML];
bool U1[2][ML][ML], U2[2][ML][ML];
int F[2][ML][ML], G[2][ML][ML];
void Calc() {
	uF(i, 0, 1) {
		dF(k, M, 1) {
			dF(j, N, 1) LCP1[i][j][k] = S[i][j] == T[k] ? 1 + LCP1[i][j + 1][k + 1] : 0;
			uF(j, 1, N) LCP2[i][j][k] = S[i][j] == T[k] ? 1 + LCP2[i][j - 1][k + 1] : 0;
		}
		uF(k, 1, M) {
			dF(j, N, 1) LCS1[i][j][k] = S[i][j] == T[k] ? 1 + LCS1[i][j + 1][k - 1] : 0;
			uF(j, 1, N) LCS2[i][j][k] = S[i][j] == T[k] ? 1 + LCS2[i][j - 1][k - 1] : 0;
		}
	}
	uF(i, 0, 1) {
		uF(j, 1, N) {
			uF(k, 2, std::min(N - j + 1, M / 2)) U1[i][j][k] = LCS1[!i][j][M] >= k && LCS2[i][j + k - 1][M - k] >= k;
			uF(k, 2, std::min(j, M / 2)) U2[i][j][k] = LCP2[!i][j][1] >= k && LCP1[i][j - k + 1][k + 1] >= k;
		}
	}
	if (~M & 1) uF(i, 1, N) {
		Add(Ans, U1[1][i][M / 2]), Add(Ans, U2[1][i][M / 2]);
		uF(j, 0, 1) uF(k, 2, M / 2 - 2) Add(Ans, U2[j][i][k] && U1[j][i + 1][M / 2 - k]);
	}
	uF(i, 1, N) {
		uF(j, 0, 1) {
			if (S[j][i] == T[1]) Add(F[j][i][1], 1);
			uF(k, 2, M / 2) if (U2[j][i - 1][k] && S[j][i] == T[k + k + 1]) Add(F[j][i][k + k + 1], 1);
			uF(k, 1, M) if (S[j][i] == T[k + 1]) Add(F[j][i][k + 1], F[j][i - 1][k]), Add(F[j][i][k + 1], G[j][i - 1][k]);
			uF(k, 1, M) if (S[!j][i] == T[k + 1]) Add(G[!j][i][k + 1], F[j][i][k]);
		}
		uF(j, 0, 1) {
			Add(Ans, F[j][i][M]), Add(Ans, G[j][i][M]);
			uF (k, 2, M / 2) if (U1[j][i + 1][k])
				Add(Ans, F[j][i][M - k - k]), Add(Ans, G[j][i][M - k - k]);
		}
	}
}

int main() {
	scanf("%s%s%s", S[0] + 1, S[1] + 1, T + 1);
	N = strlen(S[0] + 1), M = strlen(T + 1);
	if (M == 1) {
		uF(i, 0, 1) uF(j, 1, N) Ans += S[i][j] == T[1];
		return printf("%d\n", Ans), 0;
	}
	if (M == 2) {
		uF(i, 0, 1) uF(j, 1, N) if (S[i][j] == T[1])
			Ans += (S[!i][j] == T[2]) + (S[i][j - 1] == T[2]) + (S[i][j + 1] == T[2]);
		return printf("%d\n", Ans), 0;
	}
	Calc();
	std::reverse(T + 1, T + M + 1);
	memset(F, 0, sizeof F), memset(G, 0, sizeof G);
	Calc();
	printf("%d\n", Ans);
	return 0;
}