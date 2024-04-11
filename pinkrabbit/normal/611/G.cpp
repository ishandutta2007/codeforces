#include <cstdio>
#include <algorithm>

typedef long long LL;
typedef unsigned long long ULL;
const int Mod = 1000000007, Inv2 = (Mod + 1) / 2;
const int MN = 500005;

int N, px[MN * 2], py[MN * 2];
LL cross[MN * 2], SX[MN * 2], SS;
int MSpx[MN * 2], MSpy[MN * 2], MSSX[MN * 2];
int Ans;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d%d", &px[i], &py[i]);
	std::reverse(px + 1, px + N + 1), std::reverse(py + 1, py + N + 1);
	for (int i = 1; i <= N; ++i) px[N + i] = px[i], py[N + i] = py[i];
	for (int i = 2; i <= N + N; ++i) cross[i] = (LL)px[i - 1] * py[i] - (LL)py[i - 1] * px[i];
	for (int i = N + 1; i <= N + N; ++i) SS += cross[i];
	SX[1] = -SS;
	for (int i = 2; i <= N + N; ++i) SX[i] = SX[i - 1] + cross[i];
	for (int i = 1; i <= N + N; ++i)
		MSpx[i] = (MSpx[i - 1] + px[i]) % Mod,
		MSpy[i] = (MSpy[i - 1] + py[i]) % Mod,
		MSSX[i] = (MSSX[i - 1] + SX[i]) % Mod;
	int j = 2;
	for (int i = N + 1; i <= N + N; ++i) {
		auto Sum = [&]() -> LL { return SX[i] - SX[j] + ((LL)px[i] * py[j] - (LL)py[i] * px[j]); };
		while (Sum() > SS / 2) ++j;
		Ans = (Ans + SS % Mod * (i - 1 - j)) % Mod;
		Ans = (Ans - SS % Mod * (j - i + N - 2)) % Mod;
		Ans = (Ans - 2 * (SX[i] % Mod * (i - 1 - j) - (MSSX[i - 2] - MSSX[j - 1]) + (LL)px[i] * (MSpy[i - 2] - MSpy[j - 1]) - (LL)py[i] * (MSpx[i - 2] - MSpx[j - 1]))) % Mod;
		Ans = (Ans + 2 * (SX[i] % Mod * (j - i + N - 2) - (MSSX[j - 1] - MSSX[i - N + 1]) + (LL)px[i] * (MSpy[j - 1] - MSpy[i - N + 1]) - (LL)py[i] * (MSpx[j - 1] - MSpx[i - N + 1]))) % Mod;
	}
	printf("%lld\n", (LL)(Ans + Mod) * Inv2 % Mod);
	return 0;
}