#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k;
int kto[2007];
int wyn;
int ile;
int co;
int licz;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &kto[i]);
	}
	sort(kto+1, kto+1+n);
	ile=n;
	while(ile)
	{
		licz=0;
		co=0;
		while(ile && licz<k)
		{
			co=max(co, kto[ile]);
			licz++;
			ile--;
		}
		wyn+=2*(co-1);
	}
	printf("%d", wyn);
	return 0;
}