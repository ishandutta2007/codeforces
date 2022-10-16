#include <bits/stdc++.h>

using namespace std;

long long n[2],d,fq[2][40069];

int main()
{
	long long i,ii,k,ls,z=0;
	
	scanf("%lld%lld%lld",n,n+1,&d);
	for(ii=0;ii<2;ii++)
	{
		ls=0;
		for(i=1;i<=n[ii];i++)
		{
			scanf("%lld",&k);
			if(!k)
			{
				ls=i;
			}
			else
			{
				fq[ii][i-ls]++;
			}
		}
		for(i=n[ii];i;i--)
		{
			fq[ii][i]+=fq[ii][i+1];
		}
	}
	for(i=1;i*i<=d;i++)
	{
		if(d%i==0)
		{
			for(ii=0;ii<=(i!=d/i);ii++)
			{
				if(i<=n[ii]&&d/i<=n[!ii])
				{
					z+=fq[ii][i]*fq[!ii][d/i];
				}
			}
		}
	}
	printf("%lld\n",z);
}