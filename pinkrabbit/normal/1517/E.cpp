#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 998244353;
const int MN = 200005;

int N, A[MN];
LL Sum, Lim;
int Ans;

int bit[MN], siz;
void Add(int i) {
	for (; i <= siz; i += i & -i)
		++bit[i];
}
int Qur(int i) {
	int s = 0;
	for (; i; i -= i & -i)
		s += bit[i];
	return s;
}

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		scanf("%d", &N), Sum = 0;
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &A[i]);
			Sum += A[i];
		}
		Lim = (Sum - 1) / 2;
//		printf("Lim = %lld\n", Lim);
		// Sigma C <= Lim
		Ans = 0;
		if (N <= 5) {
			for (int S = 0; S < 1 << N; ++S) {
				static int aC[9], aP[9];
				int tC = 0, tP = 0;
				LL sumC = 0;
				for (int i = 0; i < N; ++i) {
					if (S >> i & 1)
						aC[++tC] = i + 1,
						sumC += A[i + 1];
					else
						aP[++tP] = i + 1;
				}
				if (sumC > Lim) continue;
				int ok = 1;
				for (int i = 2; i < tC; ++i)
					if (aC[i] - aC[i - 1] > aC[i + 1] - aC[i])
						{ ok = 0; break; }
				if (!ok) continue;
				for (int i = 2; i < tP; ++i)
					if (aP[i] - aP[i - 1] < aP[i + 1] - aP[i])
						{ ok = 0; break; }
				if (!ok) continue;
				++Ans;
//				for (int i = 0; i < N; ++i) printf("%c", S >> i & 1 ? 'C' : 'P'); puts("");
			}
			printf("%d\n", Ans);
			continue;
		}
		Ans = 1 + (A[N] <= Lim);
		static LL psum2[MN];
		psum2[1] = A[1];
		psum2[2] = A[2];
		for (int i = 3; i <= N; ++i)
			psum2[i] = psum2[i - 2] + A[i];
		static LL sarr[MN];
		static int D[MN];
		int C = 0;
		for (int i = 1; i <= N; ++i)
			sarr[++C] = psum2[i];
		std::sort(sarr + 1, sarr + C + 1);
		C = (int)(std::unique(sarr + 1, sarr + C + 1) - sarr - 1);
		auto getRank = [&](LL x) -> int {
			return (int)(std::upper_bound(sarr + 1, sarr + C + 1, x) - sarr - 1);
		};
		for (int i = 1; i <= N; ++i)
			D[i] = getRank(psum2[i]);
//		for (int i = 1; i <= N; ++i) printf("%lld%c", psum2[i], " \n"[i == N]);
//		for (int i = 1; i <= N; ++i) printf("%d%c", D[i], " \n"[i == N]);
//		printf("C = %d\n", C);
		siz = C;
		for (int i = 1; i <= C; ++i) bit[i] = 0;
		for (int i = 1; i <= N; ++i) {
			if (i & 1) { // Odd
				if (psum2[i] <= Lim) {
					LL rest = Lim - psum2[i];
					int ran = getRank(rest);
//					printf("%d : %d (ran = %d)\n", i, Qur(ran) + 1, ran);
					Ans = (Ans + (Qur(ran) + 1)) % Mod;
				}
				if (i >= 3 && psum2[i] - A[1] <= Lim) {
					LL rest = Lim - (psum2[i] - A[1]);
					int ran = getRank(rest);
					Ans = (Ans + Qur(ran)) % Mod;
				}
				if (i <= N - 3 && psum2[i] + A[N] <= Lim) {
					LL rest = Lim - (psum2[i] + A[N]);
					int ran = getRank(rest);
					Ans = (Ans + Qur(ran) + 1) % Mod;
				}
				if (i >= 3 && i <= N - 3 && psum2[i] + A[N] - A[1] <= Lim) {
					LL rest = Lim - (psum2[i] + A[N] - A[1]);
					int ran = getRank(rest);
					Ans = (Ans + Qur(ran)) % Mod;
				}
			} else Add(D[i])/*, printf("Add(%d)\n", D[i])*/;
		}
		for (int i = 1; i <= C; ++i) bit[i] = 0;
		for (int i = 1; i <= N; ++i) {
			if (~i & 1) { // Even
				if (psum2[i] <= Lim) {
					LL rest = Lim - psum2[i];
					int ran = getRank(rest);
//					printf("%d : %d (ran = %d)\n", i, Qur(ran) + 1, ran);
					Ans = (Ans + (Qur(ran) + 1)) % Mod;
				}
				if (i >= 3 && psum2[i] - A[1] <= Lim) {
					LL rest = Lim - (psum2[i] - A[1]);
					int ran = getRank(rest);
					Ans = (Ans + (Qur(ran) - (psum2[i] <= Lim))) % Mod;
				}
				if (i <= N - 3 && psum2[i] + A[N] <= Lim) {
					LL rest = Lim - (psum2[i] + A[N]);
					int ran = getRank(rest);
					Ans = (Ans + Qur(ran) + 1) % Mod;
				}
				if (i >= 3 && i <= N - 3 && psum2[i] + A[N] - A[1] <= Lim) {
					LL rest = Lim - (psum2[i] + A[N] - A[1]);
					int ran = getRank(rest);
					Ans = (Ans + (Qur(ran) - (psum2[i] + A[N] <= Lim))) % Mod;
				}
			} else Add(D[i])/*, printf("Add(%d)\n", D[i])*/;
		}
		{ // PP..CC
			LL sum = 0;
			for (int i = N; i >= 1; --i) {
				sum += A[i];
				if (sum <= Lim && (3 <= i && i <= N - 1))
					Ans = (Ans + 1) % Mod;
			}
		}
		printf("%d\n", Ans);
	}
	return 0;
}

// PCCCCCCCCCCCCPCPCPCPCPCPCPCPCPCPPPPPPPPPPPPC
// PPPPPPPPCCCCCCCC

/*
=================
2
7
2 6 7 4 3 6 4
8
6 2 3 2 1 6 9 2

-----------------
18
38

=================
*/

/*
PPPPPP -
CPPPPP
PCPPPP
CCPPPP
CPCPPP
PCCPPP   1
CCCPPP
PCPCPP
CCPCPP
PCCCPP   1
CCCCPP
CPCPCP
PCCPCP   1
CCCPCP
PCCCCP   1
CCCCCP
PPPPPC    2
CPPPPC    2
PCPPPC    2
CCPPPC    2
CPCPPC    2
PCCPPC     3
CCCPPC    2
PCPCPC
CCPCPC
PCCCPC   1
CCCCPC
PPPPCC ;
PPPCCC ;
PPCCCC ;
PCCCCC   1
CCCCCC x
*/