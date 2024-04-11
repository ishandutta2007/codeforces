#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],wg[100069];

int main()
{
	long long i,ii,c,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",wg+i);
	}
	for(ii=0;ii<2;ii++)
	{
		c=0;
		for(i=1;i<=n;i++)
		{
			c+=wg[i];
			z+=max(a[i]-c*d,0ll);
		}
		for(i=1;i<n+1-i;i++)
		{
			swap(a[i],a[n+1-i]);
			swap(wg[i],wg[n+1-i]);
		}
		z*=-1;
	}
	if(z>0)
	{
		printf("Limak\n");
	}
	else if(z<0)
	{
		printf("Radewoosh\n");
	}
	else
	{
		printf("Tie\n");
	}
}