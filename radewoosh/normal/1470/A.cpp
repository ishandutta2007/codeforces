#include <bits/stdc++.h>
using namespace std;

int t, n, m, kt[1000000], tab[1000000];

main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		for (int i=1; i<=n; i++)
			scanf("%d", &kt[i]);
		for (int i=1; i<=m; i++)
			scanf("%d", &tab[i]);
		for (int i=1; i<=n; i++)
			tab[m+i]=tab[kt[i]];
		sort(tab+1, tab+1+n+m);
		long long wyn=0;
		for (int i=1; i<=n; i++)
			wyn+=tab[i];
		printf("%lld\n", wyn);
	}
}