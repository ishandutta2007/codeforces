#include<cstdio>

const int MOD = (int) 1e9;

int n, m, a[1000], f[1000], t, k, l;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < n; i++)
	{
		f[i] = (f[i - 1] + f[i - 2]) % MOD;		
	}
	for (int i = 0; i < m; i++)
	{
		long long ans = 0;
		scanf("%d%d%d", &t, &k, &l);
		if (t == 1)
			a[k - 1] = l;
		if (t == 2)
		{
			k--;
			l--;
			for (int i = k; i <= l; i++)
			{
				ans = (ans + ((long long) a[i] * (long long) f[i - k]) % MOD) % MOD;
		   	}
		   	printf("%I64d\n", ans);
		}
		if (t == 3)
			scanf("%d", &k);	
	}
	return 0;
}