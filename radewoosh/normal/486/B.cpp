#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
int tab[107][107];
int pew[107][107];
int now[107][107];
int sta[107][107];

int main()
{
	scanf("%d%d", &m, &n);
	for (int i=1; i<=m; i++)
	{
		for (int j=1; j<=n; j++)
		{
			scanf("%d", &tab[i][j]);
			if (!tab[i][j])
			{
				for (int k=1; k<=m; k++)
				{
					pew[k][j]=1;
				}
				for (int k=1; k<=n; k++)
				{
					pew[i][k]=1;
				}
			}
		}
	}
	for (int i=1; i<=m; i++)
	{
		for (int j=1; j<=n; j++)
		{
			now[i][j]=!pew[i][j];
		}
	}
	for (int i=1; i<=m; i++)
	{
		for (int j=1; j<=n; j++)
		{
			for (int k=1; k<=m; k++)
			{
				sta[i][j]|=now[k][j];
			}
			for (int k=1; k<=n; k++)
			{
				sta[i][j]|=now[i][k];
			}
			if (sta[i][j]!=tab[i][j])
			{
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES\n");
	for (int i=1; i<=m; i++)
	{
		for (int j=1; j<=n; j++)
		{
			printf("%d ", now[i][j]);
		}
		printf("\n");
	}
	return 0;
}