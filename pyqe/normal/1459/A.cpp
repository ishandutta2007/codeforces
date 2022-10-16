#include <bits/stdc++.h>

using namespace std;

long long n,a[1069];

int main()
{
	long long t,rr,i,ii,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf(" %c",&ch);
				a[i]=-a[i]-(ch-'0');
			}
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			z+=(a[i]>0)-(a[i]<0);
			a[i]=0;
		}
		if(z>0)
		{
			printf("RED\n");
		}
		else if(z<0)
		{
			printf("BLUE\n");
		}
		else
		{
			printf("EQUAL\n");
		}
	}
}