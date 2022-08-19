#include <bits/stdc++.h>
using namespace std;

using ll=long long;

ll a[4];

int main()
{
	for (int i=1; i<=3; i++)
		scanf("%lld", &a[i]);
	printf("First\n");
	fflush(stdout);
	int p=-1;
	while(p)
	{
		ll b[]={a[1], a[2], a[3]};
		sort(b, b+3);
		ll y=b[2]-b[1];
		ll x=b[1]-b[0];
		ll w=(rand()&1) ? y : x+2*y;
		printf("%lld\n", w);
		fflush(stdout);
		scanf("%d", &p);
		a[p]+=w;
	}
	return 0;
}