#include <bits/stdc++.h>
using namespace std;

int n;

int tab[2000007];

int wyn;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		int p1;
		scanf("%d", &p1);
		tab[p1]++;
	}
	for (int i=0; i<=2000000; i++)
	{
		wyn+=(tab[i]&1);
		tab[i+1]+=(tab[i]/2);
	}
	printf("%d\n", wyn);
	return 0;
}