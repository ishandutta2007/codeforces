#include<cstdio>

int na, ma, nb, mb, a[100][100], b[100][100], ans, max1 = -100, k, l;
char s[1000]; 

int main()
{
	scanf("%d%d\n", &na, &ma);
	for (int i = 0; i < na; i++)
	{
		gets(s);
		for (int j = 0; j < ma; j++)
			a[i + 1][j + 1] = (int) (s[j] - '0');
	}
	scanf("%d%d\n", &nb, &mb);
	for (int i = 0; i < nb; i++)
	{
		gets(s);
		for (int j = 0; j < mb; j++)
			b[i + 1][j + 1] = (int) (s[j] - '0');
	}
	for (int x = -50; x < 51; x++)
		for (int y = -50; y < 51; y++)
		{
			ans = 0;
			for (int i = 1; i <= na; i++)
				for (int j = 1; j <= ma; j++)
				{                                                        
					if (i + x >= 1 && i + x <= nb && j + y >= 1 && j + y <= mb)
					{
						ans += a[i][j] * b[i + x][j + y];
					}
				}
		 	if (ans > max1)
		 	{
		 		max1 = ans;
		 		k = x;
		 		l = y;
		 	}
		}
	printf("%d %d\n", k, l);
	return 0;
}