#include <iostream>
#include <cstdio>
using namespace std;

int n, k;
long long tab[50][50];
long long wyn=1;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		tab[1][i]=1;
		tab[i][1]=1;
	}
	for (int i=2; i<=n; i++)
	{
		for (int j=2; j<=n; j++)
		{
			tab[i][j]=tab[i][j-1]+tab[i-1][j];
		}
	}
	printf("%lld", tab[n][n]);
	return 0;
}