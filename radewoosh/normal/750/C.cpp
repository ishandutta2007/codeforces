#include <bits/stdc++.h>
using namespace std;

void nope()
{
	printf("Impossible\n");
	exit(0);
}

int n;

int d;
long long zm;

long long g=1900;

long long inf=1000000000;

long long l=-inf, r=inf;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%d", &zm, &d);
		if (d==1)
		{
			if (r<g)
				nope();
			l=max(l, g);
		}
		else
		{
			if (l>=g)
				nope();
			r=min(r, g-1);
		}
		l+=zm;
		r+=zm;
	}
	if (r>=(inf/2))
		printf("Infinity\n");
	else
		printf("%lld\n", r);
	return 0;
}