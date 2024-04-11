#include <bits/stdc++.h>


const int mod = 1e9 + 7;
int f[705][705][10][2];
// f[i][j][k][0/1] i  >= k  j /
char s[1005];

int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) s[i] -= 48;
	for (int i = 0; i <= 9; ++i) f[0][0][i][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < i; ++j)
			for (int k = 1; k <= 9; ++k)
				for (int o = 0; o <= 1; ++o)
					for (int t = 0; t <= (o ? 9 : s[i]); ++t)
					{
						int x = j + (t >= k), y = o | (t < s[i]);
						f[i][x][k][y] += f[i - 1][j][k][o];
						if (f[i][x][k][y] >= mod) f[i][x][k][y] -= mod;
					}
	int ans = 0;
	
	for (int i = 0; i <= 9; ++i)
	{
		int p = 1;
		for (int j = 1; j <= n; ++j)
		{
			ans += 1ll * p * (f[n][j][i][0] + f[n][j][i][1]) % mod;
			if (ans >= mod) ans -= mod;
			p = (10ll * p + 1) % mod;
		}
	}
	printf("%d\n", ans);
				
	return 0;
}