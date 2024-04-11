#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, p;
string slo;
int tab[100007];
int ile[100007];
int sum;
int mini=1000000;
int maxi;

int main()
{
	scanf("%d%d", &n, &p);
	cin >> slo;
	for (int i=0; i<n; i++)
	{
		tab[i+1]=slo[i]-'a';
	}
	for (int i=1; i<=n; i++)
	{
		ile[i]=(tab[i]-tab[n+1-i]+26)%26;
		ile[i]=min(ile[i], 26-ile[i]);
	}
	if (p>=n/2)
	{
		p=n+1-p;
	}
	for (int i=1; i<=n/2; i++)
	{
		sum+=ile[i];
		if (ile[i])
		{
			mini=min(mini, i);
			maxi=max(maxi, i);
		}
	}
	if (!sum)
	{
		printf("0");
		return 0;
	}
	if (p>maxi)
	{
		printf("%d", sum+p-mini);
		return 0;
	}
	if (p<mini)
	{
		printf("%d", sum+maxi-p);
		return 0;
	}
	printf("%d", sum+maxi-mini+min(p-mini, maxi-p));
	return 0;
}