#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, w, m;
long long tab[500007];
long long ro[500007];
int kmp[500007];
int wyn;
int it;

int main()
{
	scanf("%d%d", &n, &w);
	m=n+1+w;
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[w+i]);
	}
	for (int i=1; i<=w; i++)
	{
		scanf("%lld", &tab[i-1]);
	}
	tab[w]=-1;
	tab[w]*=1000;
	tab[w]*=1000;
	tab[w]*=1000;
	tab[w]*=1000;
	for (int i=1; i<m; i++)
	{
		ro[i]=tab[i]-tab[i-1];
	}
	for (int i=2; i<m; i++)
	{
		it=kmp[i-1];
		while(it && ro[i]!=ro[it+1])
		{
			it=kmp[it];
		}
		if (ro[it+1]==ro[i])
		kmp[i]=it+1;
		if (kmp[i]==w-1)
		wyn++;
	}
	printf("%d", wyn);
	return 0;
}