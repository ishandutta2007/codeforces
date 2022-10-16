#include <bits/stdc++.h>

using namespace std;

long long n,fq[69],fc[69];

int main()
{
	long long t,rr,i,ii,k,sm,z,zzz;
	
	fc[0]=1;
	for(i=1;i<=20;i++)
	{
		fc[i]=fc[i-1]*i;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<20;i++)
		{
			fq[i]=0;
		}
		scanf("%lld",&k);
		for(n=1;1;n++)
		{
			fq[k%n]++;
			k/=n;
			if(!k)
			{
				break;
			}
		}
		zzz=0;
		for(ii=0;ii<2;ii++)
		{
			fq[0]-=ii;
			if(fq[0]>=0)
			{
				sm=0;
				z=1;
				for(i=1;i<=n-ii;i++)
				{
					sm+=fq[i-1];
					z*=sm;
					sm--;
				}
				for(i=0;i<n;i++)
				{
					z/=fc[fq[i]];
				}
			}
			else
			{
				z=0;
			}
			zzz=-zzz-z;
		}
		printf("%lld\n",zzz-1);
	}
}