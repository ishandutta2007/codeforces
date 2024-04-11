#include <bits/stdc++.h>

using namespace std;

const long long ma=100;
long long n,fq[2][269];

int main()
{
	long long t,rr,i,ii,k,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=ma*2+1;i++)
			{
				fq[ii][i]=0;
			}
			for(i=0;i<n;i++)
			{
				scanf("%lld",&k);
				fq[ii][ma+1+k]++;
			}
		}
		for(i=1;i<=ma*2+1;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				w=min(fq[0][i],fq[1][i+ii]);
				fq[0][i]-=w;
				fq[1][i+ii]-=w;
			}
			if(fq[0][i])
			{
				break;
			}
		}
		if(i>ma*2+1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}