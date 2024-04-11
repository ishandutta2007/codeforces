#include <bits/stdc++.h>

using namespace std;

long long n,nn,fq[2000069],mn[2000069],sm[2000069],c[2000069];

int main()
{
	long long t,rr,i,j,k,tg,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n+1;i++)
		{
			fq[i]=0;
			sm[i]=0;
			c[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			fq[k]++;
		}
		nn=0;
		for(i=1;i<=n;i++)
		{
			if(fq[i])
			{
				nn++;
				for(j=1;j<=fq[i]+1;j++)
				{
					mn[j]=1e18;
				}
				for(j=fq[i];j>0;j--)
				{
					mn[fq[i]/j+1]=j;
					if(fq[i]/j*j==fq[i])
					{
						mn[fq[i]/j]=j;
					}
				}
				for(j=1;j<=fq[i]+1;j++)
				{
					if(mn[j]<1000000000000000000)
					{
						sm[j]+=mn[j];
						c[j]++;
					}
				}
			}
		}
		z=1e18;
		for(i=1;i<=n+1;i++)
		{
			if(c[i]==nn)
			{
				z=min(z,sm[i]);
			}
		}
		printf("%lld\n",z);
	}
}