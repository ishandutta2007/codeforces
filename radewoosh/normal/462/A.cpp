#include <iostream>
#include <cstdio>
using namespace std;

int n;
string slo;;
int tab[107][107];
int num;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		cin >> slo;
		for (int j=1; j<=n; j++)
		{
			tab[i][j]=(slo[j-1]=='o');
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			num=tab[i][j-1]+tab[i][j+1]+tab[i-1][j]+tab[i+1][j];
			if (num%2)
			{
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
	return 0;
}