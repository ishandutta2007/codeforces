#include <bits/stdc++.h>
using namespace std;

int n, m;

int l, p;

int mini=1000000000;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d", &l, &p);
		mini=min(mini, p-l+1);
	}
	printf("%d\n", mini);
	for (int i=1; i<=n; i++)
		printf("%d ", (i%mini));
	printf("\n");
	return 0;
}