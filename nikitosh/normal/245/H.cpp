#include<cstdio>
#include<cstring>

bool a[5005][5005];
int d[5005][5005];
char s[5005];
int n, r;

int main()
{
	gets(s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		d[i][i] = 1;
		a[i][i] = 1;
	}
	for (int i = 0; i < n - 1; i++)
		if (s[i] == s[i + 1])
		{
			d[i][i + 1] = 3;
			a[i][i + 1] = 1;
		}
		else
			d[i][i + 1] = 2;
	for (int len = 2; len < n; len++)
		for (int l = 0; l < n; l++)
			if (l + len < n)
			{
				r = l + len;
				d[l][r] = d[l + 1][r] + d[l][r - 1] - d[l + 1][r - 1];
				if (s[l] == s[r] && a[l + 1][r - 1] == 1)
				{
					d[l][r]++;
					a[l][r] = 1;
				}
			}
	int q, a, b;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &a, &b);
		a--;
		b--;
		printf("%d\n", d[a][b]);
	}
	return 0;
}