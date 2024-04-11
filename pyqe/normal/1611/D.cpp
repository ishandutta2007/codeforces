#include <bits/stdc++.h>

using namespace std;

long long n,pr[200069],a[200069],sq[200069];

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",pr+i);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			a[k]=i;
		}
		for(i=1;i<=n;i++)
		{
			sq[i]=a[i]-a[pr[i]];
			if(sq[i]<0)
			{
				break;
			}
		}
		if(i>n)
		{
			for(i=1;i<=n;i++)
			{
				printf("%lld%c",sq[i]," \n"[i==n]);
			}
		}
		else
		{
			printf("-1\n");
		}
	}
}