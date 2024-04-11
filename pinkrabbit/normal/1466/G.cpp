#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

typedef long long LL;
const int Mod = 1000000007;
const int Inv2 = (Mod + 1) / 2;
const int MS = 1000005;
const int MN = 100005;
const int Sig = 26;

int _pw2[MN * 2], *pw2 = _pw2 + MN;
void Init(int N) {
	pw2[0] = 1;
	for (int i = 1; i <= N; ++i) pw2[i] = 2 * pw2[i - 1] % Mod;
	for (int i = -1; i >= -N; --i) pw2[i] = (LL)Inv2 * pw2[i + 1] % Mod;
}

inline int KMP(char *s, int n, char *t, int m) {
	static int fail[MS];
	fail[1] = 0;
	for (int i = 2, k = 0; i <= n; ++i) {
		while (k && s[k + 1] != s[i]) k = fail[k];
		if (s[k + 1] == s[i]) ++k;
		fail[i] = k;
	}
	int cnt = 0;
	for (int i = 1, k = 0; i <= m; ++i) {
		while (k && s[k + 1] != t[i]) k = fail[k];
		if (s[k + 1] == t[i]) ++k;
		if (k == n) ++cnt, k = fail[k];
	}
	return cnt;
}

int Z[MS * 3];
inline void Zfunc(char *s, int n) {
//	for (int i = 1; i <= n; ++i) printf("%c", s[i]); puts("");
	Z[1] = -1;
	int l = 1, r = 0;
	for (int i = 2; i <= n; ++i) {
		if (i <= r) Z[i] = std::min(Z[i - (l - 1)], r - i + 1);
		else Z[i] = 0;
		while (i + Z[i] <= n && s[1 + Z[i]] == s[i + Z[i]]) ++Z[i];
		if (i + Z[i] - 1 > r)
			l = i, r = i + Z[i] - 1;
	}
	Z[n + 1] = 0;
//	for (int i = 1; i <= n; ++i) printf("%d, ", Z[i]); puts("");
}

int N, Q, Y;
char s0[105], t[MN];
char _str[MS * 4], *str[MN];
int len[MN];

int sc[MN][Sig];

int main() {
	Init(100000);
	scanf("%d%d%s%s", &N, &Q, s0 + 1, t + 1), len[0] = strlen(s0 + 1);
	str[0] = _str, memcpy(str[0] + 1, s0 + 1, len[0]);
	for (int i = 1; i <= N; ++i) {
		len[i] = 2 * len[i - 1] + 1;
		str[i] = str[i - 1] + len[i - 1];
		memcpy(str[i] + 1, str[i - 1] + 1, len[i - 1]);
		str[i][len[i - 1] + 1] = t[i];
		memcpy(str[i] + len[i - 1] + 2, str[i - 1] + 1, len[i - 1]);
		Y = i;
		if (len[i] >= 1000000) break;
	}
	for (int i = 1; i <= N; ++i) {
		for (int p = 0; p < Sig; ++p) sc[i][p] = sc[i - 1][p];
		int c = t[i] - 'a';
		sc[i][c] = (sc[i][c] + pw2[-i]) % Mod;
	}
//	for (int i = 0; i <= Y; ++i) {
//		printf("%d : ", i);
//		for (int j = 1; j <= len[i]; ++j) printf("%c", str[i][j]);
//		puts("");
//	}
	for (int q = 1; q <= Q; ++q) {
		static char qs[MS];
		int k, ql, ans = 0;
		scanf("%d%s", &k, qs + 1), ql = strlen(qs + 1);
		if (ql > len[std::min(k, Y)]) { puts("0"); continue; }
		
		int j = 0;
		while (len[j] < ql) ++j;
		// |str[j]| >= qlen
//		printf("j = %d (len[j] = %d)\n", j, len[j]);
		
		ans = (ans + (LL)pw2[-j] * KMP(qs, ql, str[j], len[j])) % Mod;
		
		static int cnt[Sig];
		for (int p = 0; p < Sig; ++p) cnt[p] = (sc[k][p] - sc[j][p] + Mod) % Mod;
		
		static char tmp[MS * 3];
		static bool ok[MS];
		memcpy(tmp + 1, str[j] + 1, len[j]);
		tmp[len[j] + 1] = '*';
		memcpy(tmp + len[j] + 2, qs + 1, ql);
		Zfunc(tmp, len[j] + ql + 1);
		for (int i = 1; i <= ql; ++i) ok[i] = (Z[len[j] + i + 2] == ql - i);
//		for (int i = 1; i <= ql; ++i) printf("ok[%d] = %d\n", i, ok[i]);
		std::reverse(tmp + 1, tmp + len[j] + 1);
		std::reverse(tmp + len[j] + 2, tmp + len[j] + ql + 2);
		Zfunc(tmp, len[j] + ql + 1);
		for (int i = 1; i <= ql; ++i) if (ok[i]) {
			if (Z[len[j] + ql - i + 3] != i - 1) continue;
//			printf("ok : %d\n", i);
			ans = (ans + cnt[qs[i] - 'a']) % Mod;
		}
		
		ans = (LL)ans * pw2[k] % Mod;
		printf("%d\n", ans);
	}
	return 0;
}

/*
10 10
a
bcdefghidk
8 acabada
9 acabada
10 acabada

*/