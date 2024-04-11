#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 2005;

inline void Add(int &x, int y) {
	x -= Mod - y;
	x += x >> 31 & Mod;
}

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		int N;
		static char A[MN], B[MN];
		scanf("%d%s%s", &N, A + 1, B + 1);
		static int f_[2][MN * 2], g_[2][MN * 2];
		int *f0 = f_[0] + MN, *f1 = f_[1] + MN;
		int *g0 = g_[0] + MN, *g1 = g_[1] + MN;
		f0[0] = 1, g0[0] = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = -i; j <= i; ++j)
				f1[j] = g1[j] = 0;
			for (int ca = 0; ca < 2; ++ca) if ((ca ^ (~i & 1)) + '0' != A[i])
				for (int cb = 0; cb < 2; ++cb) if ((cb ^ (~i & 1)) + '0' != B[i]) {
					int c = ca - cb;
					for (int j = -i + 1; j <= i - 1; ++j) if (f0[j] || g0[j]) {
						Add(f1[j + c], f0[j]);
						g1[j + c] = (g1[j + c] + g0[j] + (LL)f0[j] * std::abs(j + c)) % Mod;
					}
				}
			std::swap(f0, f1);
			std::swap(g0, g1);
		}
		printf("%d\n", g0[0]);
	}
	return 0;
}