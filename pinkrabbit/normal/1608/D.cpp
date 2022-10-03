#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 998244353;
const int MS = 200005;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (int)((LL)b * b % Mod))
		if (e & 1) a = (int)((LL)a * b % Mod);
	return a;
}
inline int gInv(int b) { return qPow(b, Mod - 2); }

int Fac[MS], iFac[MS];
inline void Init(int N) {
	Fac[0] = 1;
	for (int i = 1; i <= N; ++i) Fac[i] = (int)((LL)Fac[i - 1] * i % Mod);
	iFac[N] = gInv(Fac[N]);
	for (int i = N; i >= 1; --i) iFac[i - 1] = (int)((LL)iFac[i] * i % Mod);
}
inline int Binom(int N, int M) {
	if (M < 0 || M > N) return 0;
	return (int)((LL)Fac[N] * iFac[M] % Mod * iFac[N - M] % Mod);
}

int main() {
	static const int MN = 100005;
	int N;
	static char str[MN][5];
	scanf("%d", &N);
	Init(2 * N);
	int cnt = 0, pw = 0, prd = 1;
	for (int i = 1; i <= N; ++i) {
		scanf("%s", str[i]);
		if (str[i][0] == '?' && str[i][1] == '?')
			cnt += 2, pw += 1, prd = 2 * prd % Mod;
		else if (str[i][0] == '?')
			cnt += 1, pw += str[i][1] == 'B';
		else if (str[i][1] == '?')
			cnt += 1, pw += str[i][0] == 'B';
		else if (str[i][0] == str[i][1])
			pw += str[i][0] == 'B' ? 1 : -1, prd = 0;
	}
	int ok1 = 1, ok2 = 1;
	for (int i = 1; i <= N; ++i) {
		if (str[i][0] == 'B' || str[i][1] == 'W') ok1 = 0;
		if (str[i][0] == 'W' || str[i][1] == 'B') ok2 = 0;
	}
	int ans = (Binom(cnt, pw) - prd + ok1 + ok2 + Mod) % Mod;
	printf("%d\n", ans);
	return 0;
}