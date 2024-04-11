#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000;
char s[maxn + 10], t[maxn + 10];
int n, m, f[maxn + 10][maxn + 10];
int main() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1); m = strlen(t + 1);
	memset(f, -0x3f, sizeof f); f[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		int pos = 0;
		for (int j = i, p = m; j >= 1; --j) {
			if (s[j] == t[p]) --p;
			if (!p) {
				pos = j; break;
			}
		}
		for (int j = 0; j <= n; ++j) {
			f[i][j] = f[i - 1][j];
			if (j) f[i][j] = max(f[i][j], f[i - 1][j - 1]);
			if (pos && j >= i - pos + 1 - m)
				f[i][j] = max(f[i][j], f[pos - 1][j - (i - pos + 1 - m)] + 1);
			if (i == n) printf("%d ", f[i][j]);
		}
	}
}