#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,df[1000069],sk[1000069];

int main()
{
	long long i,j,k,w,sm=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		k-=sm;
		if(i-1)
		{
			nn++;
			sk[nn]=i;
			df[i]=1;
		}
		for(;k;)
		{
			if(nn)
			{
				w=min(i+1-sk[nn],k);
				k-=w;
				sk[nn]+=w;
				if(sk[nn]>i)
				{
					nn--;
					sm++;
				}
			}
			else
			{
				df[1]+=(k-1)/i+1;
				sm+=k/i;
				if(k%i)
				{
					nn++;
					sk[nn]=k%i+1;
				}
				k=0;
			}
		}
	}
	for(i=1;i<=nn;i++)
	{
		df[sk[i]]=0;
	}
	sm=0;
	for(i=1;i<=n;i++)
	{
		sm+=df[i];
		printf("%lld%c",sm," \n"[i==n]);
	}
}