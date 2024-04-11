#include <cstdio>
#include <algorithm>

const int MN = 2005;

int N, B[26];
char s[MN], t[MN];
int f[MN][MN], b1[26], b2[26];

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		scanf("%d%s%s", &N, s + 1, t + 1);
		for (int i = 1; i <= N; ++i) ++B[s[i] - 'a'];
		for (int i = 1; i <= N; ++i) --B[t[i] - 'a'];
		int ok = 1;
		for (int k = 0; k < 26; ++k) if (B[k]) B[k] = ok = 0;
		if (!ok) { puts("-1"); continue; }
		for (int k = 0; k < 26; ++k) b2[k] = 0;
		for (int j = 1; j <= N; ++j) {
			++b2[t[j] - 'a'];
			f[0][j] = 0;
			for (int k = 0; k < 26; ++k) b1[k] = 0;
			for (int i = 1; i <= j; ++i) {
				++b1[s[i] - 'a'];
				f[i][j] = f[i - 1][j] + 1;
				if (s[i] == t[j]) f[i][j] = std::min(f[i][j], f[i - 1][j - 1]);
				if (b1[t[j] - 'a'] < b2[t[j] - 'a']) f[i][j] = std::min(f[i][j], f[i][j - 1]);
			}
		}
		printf("%d\n", f[N][N]);
	}
	return 0;
}