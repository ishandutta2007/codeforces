#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
char tab[1000007];
int a;
int ile[1000007];
int stan;

int main()
{
	scanf("%s", &tab);
	for (int i=0; 1; i++)
	{
		if (!tab[i])
		{
			n=i;
			break;
		}
	}
	for (int i=n; i; i--)
	{
		tab[i]=tab[i-1];
	}
	scanf("%d", &m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d", &a);
		ile[a]^=1;
		ile[n-a+1]^=1;
	}
	for (int i=1; i<=n; i++)
	{
		if (i<=n/2)
		stan^=ile[i];
		if (!stan)
		printf("%c", tab[i]);
		else
		printf("%c", tab[n-i+1]);
		if (i>n/2)
		stan^=ile[i];
	}
	return 0;
}