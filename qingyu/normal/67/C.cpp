#include <bits/stdc++.h>

const int N = 5e3 + 50;

int n, m, a, b, c, d, f[N][N], fs[27], ft[27];
char s[N], t[N];
int main()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	for (int i = 1; i <= n; ++i) s[i] -= 'a';
	for (int i = 1; i <= m; ++i) t[i] -= 'a';
	for (int i = 1; i <= m; ++i) f[0][i] = f[0][i - 1] + a;
	for (int i = 1; i <= n; ++i)
	{
		f[i][0] = f[i - 1][0] + b;
		memset(ft, 0, sizeof ft);
		for (int j = 1; j <= m; ++j)
		{
			f[i][j] = std::min(f[i][j - 1] + a, std::min(f[i - 1][j] + b, f[i - 1][j - 1] + (s[i] == t[j] ? 0 : c)));
			int k = fs[t[j]], l = ft[s[i]];
			if (k > 0 && l > 0) f[i][j] = std::min(f[i][j], f[k - 1][l - 1] + (i - k - 1) * b + d + (j - l - 1) * a);
			ft[t[j]] = j;
		}
		fs[s[i]] = i;
	}
	printf("%d", f[n][m]);
	return 0;
}