#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, s;
int wyn=-1;
int dol, cen;

int main()
{
	scanf("%d%d", &n, &s);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d", &dol, &cen);
		if (dol+(cen>0)>s)
		continue;
		if (!cen)
		wyn=max(wyn, 0);
		else
		wyn=max(wyn, 100-cen);
	}
	printf("%d", wyn);
	return 0;
}