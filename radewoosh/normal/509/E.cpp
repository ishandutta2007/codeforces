#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char tab[1000007];
double sum[1000007];
double aktudod;
double wyn;

int main()
{
	scanf("%s", &tab);
	for (int i=0; 1; i++)
	{
		if (tab[i]==0)
		{
			n=i;
			break;
		}
	}
	for (int i=1; i<=n; i++)
	{
		sum[i]=sum[i-1]+1.0/i;
	}
	aktudod=sum[n];
	for (int i=0; i<n; i++)
	{
		//printf("%d %f\n", i, aktudod);
		if (tab[i]=='I' || tab[i]=='E' || tab[i]=='A' || tab[i]=='O' || tab[i]=='U' || tab[i]=='Y')
		{
			wyn+=aktudod;
		}
		aktudod+=sum[n-1-i]-sum[i+1];
		//printf(" %d %d\n", n-1-i, n);
	}
	printf("%.8f", wyn);
	return 0;
}