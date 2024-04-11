#include <bits/stdc++.h>
 
typedef long long ll;
 
ll d, m;
ll f[50][50], c[50];
 
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld%lld", &d, &m);
		memset(f, 0, sizeof f);
		ll k = 0;
		while ((1 << k) <= d) ++k;
		--k;
		f[0][0] = 1;
		for (int i = 1; i <= k; ++i) c[i] = (1 << (i - 1)) % m; c[k + 1] = d - (1 << k) + 1;
		//dp[i][j] ij
		for (int i = 1; i <= k + 1; ++i) for (int j = 0; j <= k + 1; ++j)
		{
			f[i][j] = f[i - 1][j];
			if (j > 0) f[i][j] = (f[i][j] + f[i - 1][j - 1] * c[i]) % m;
		}
		ll ans = 0;
		for (int i = 1; i <= k + 1; ++i) ans = (ans + f[k + 1][i]) % m;
		printf("%lld\n", ans);
	}
}