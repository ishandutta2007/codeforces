#include <bits/stdc++.h>
using namespace std;

int n;

int per[1000007];
int x;
int xo=1;

int cyk;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &per[i]);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &x);
		xo^=x;
	}
	for (int i=1; i<=n; i++)
	{
		if (!per[i])
			continue;
		cyk++;
		int v=i;
		while(per[v])
		{
			x=per[v];
			per[v]=0;
			v=x;
		}
	}
	if (cyk==1)
		cyk=0;
	printf("%d\n", xo+cyk);
	return 0;
}