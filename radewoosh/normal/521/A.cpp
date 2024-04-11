#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
string slo;

int tab[5];
int maxi;
long long mod=1000000007;
long long wyn=1;
int ile;

int main()
{
	cin >> n;
	cin >> slo;
	for (int i=0; i<n; i++)
	{
		if (slo[i]=='A')
		{
			tab[1]++;
		}
		if (slo[i]=='C')
		{
			tab[2]++;
		}
		if (slo[i]=='G')
		{
			tab[3]++;
		}
		if (slo[i]=='T')
		{
			tab[4]++;
		}
	}
	maxi=max( max(tab[1], tab[2]) , max(tab[3], tab[4]) );
	//printf("%d", maxi);
	for (int i=1; i<=4; i++)
	{
		if (tab[i]==maxi)
		{
			ile++;
		}
	}
	for (int i=1; i<=n; i++)
	{
		wyn*=ile;
		wyn%=mod;
	}
	printf("%lld", wyn);
	return 0;
}