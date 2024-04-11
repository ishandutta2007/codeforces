#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<1069> a[2];

int main()
{
	long long t,rr,i,j,ii,k,z[2];
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				a[ii][i]=0;
			}
			swap(n,m);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%lld",&k);
				for(ii=0;ii<2;ii++)
				{
					a[ii][i]=a[ii][i]|k;
					swap(i,j);
				}
			}
		}
		for(ii=0;ii<2;ii++)
		{
			z[ii]=0;
			for(i=1;i<=n;i++)
			{
				z[ii]+=!a[ii][i];
			}
			swap(n,m);
		}
		if(min(z[0],z[1])%2)
		{
			printf("Ashish\n");
		}
		else
		{
			printf("Vivek\n");
		}
	}
}