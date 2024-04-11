#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <bitset>
using namespace std;

int n, m;
int tab[2007][2007];
char wcz[2007];

void check(int x, int y)
{
	if (x<1 || x>n || y<1 || y>m)
	return;
	if (tab[x][y])
	return;
	if (tab[x-1][y] && tab[x][y-1] && tab[x-1][y-1])
	{
		tab[x][y]=1;
		check(x-1, y-1);
		check(x+1, y-1);
		check(x-1, y+1);
		check(x+1, y+1);
		check(x, y-1);
		check(x, y+1);
		check(x-1, y);
		check(x+1, y);
		return;
	}
	if (tab[x+1][y] && tab[x][y-1] && tab[x+1][y-1])
	{
		tab[x][y]=1;
		check(x-1, y-1);
		check(x+1, y-1);
		check(x-1, y+1);
		check(x+1, y+1);
		check(x, y-1);
		check(x, y+1);
		check(x-1, y);
		check(x+1, y);
		return;
	}
	if (tab[x-1][y] && tab[x][y+1] && tab[x-1][y+1])
	{
		tab[x][y]=1;
		check(x-1, y-1);
		check(x+1, y-1);
		check(x-1, y+1);
		check(x+1, y+1);
		check(x, y-1);
		check(x, y+1);
		check(x-1, y);
		check(x+1, y);
		return;
	}
	if (tab[x+1][y] && tab[x][y+1] && tab[x+1][y+1])
	{
		tab[x][y]=1;
		check(x-1, y-1);
		check(x+1, y-1);
		check(x-1, y+1);
		check(x+1, y+1);
		check(x, y-1);
		check(x, y+1);
		check(x-1, y);
		check(x+1, y);
		return;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", &wcz);
		for (int j=1; j<=m; j++)
		{
			if (wcz[j-1]=='.')
			tab[i][j]=1;
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			check(i, j);
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (tab[i][j])
			printf(".");
			else
			printf("*");
		}
		printf("\n");
	}
	return 0;
}