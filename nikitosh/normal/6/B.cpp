#include<cstdio>

int n, m, used[105], ans = 0;
char s[105], a[105][105], c, l;

int main()
{
	scanf("%d%d %c\n", &n, &m, &c);
	for (int i = 1; i <= n; i++)
	{
		gets(s);
		for (int j = 1; j <= m; j++)
			a[i][j] = s[j - 1];
	}	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] == c)
			{
				l = a[i - 1][j];
				if (l >= 'A' && l <= 'Z' && l != c)
					used[l - 'A'] = 1;
				l = a[i + 1][j];
				if (l >= 'A' && l <= 'Z' && l != c)
					used[l - 'A'] = 1;
				l = a[i][j - 1];
				if (l >= 'A' && l <= 'Z' && l != c)
					used[l - 'A'] = 1;
				l = a[i][j + 1];
				if (l >= 'A' && l <= 'Z' && l != c)
					used[l - 'A'] = 1;
			}
   	for (int i = 0; i < 100; i++)
   		ans += used[i];
   	printf("%d\n", ans);
	return 0;
}