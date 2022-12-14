#include<cstdio>

int n, m, x, y, tx[1005], ty[1005], ans, sz;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		x--;
		y--;
		tx[x] = 1;
		ty[y] = 1;		
	}
	for (int i = 1; i < (n + 1) / 2; i++)
	{
		if (n % 2 == 1 && i == n / 2)
		{
			if (tx[i] == 1 && ty[i] == 1)
				continue;
			ans++;
	    	continue;
	    }
	    sz = tx[i] + tx[n - i - 1] + ty[i] + ty[n - i - 1];
		ans += 4 - sz;
	}
	printf("%d\n", ans);
	return 0;
}