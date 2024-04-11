#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[200069],dp[400069][20];

int main()
{
	long long i,j,ii,k,kk,z,mn=1e18;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(i=200000;i>=0;i--)
	{
		for(ii=i*2;ii<i*2+2;ii++)
		{
			if(ii!=i)
			{
				for(j=1;j<20;j++)
				{
					dp[i][j]+=dp[ii][j-1];
				}
			}
		}
		dp[i][0]=fq[i];
		z=0;
		kk=d;
		for(j=0;j<20;j++)
		{
			k=min(kk,dp[i][j]);
			z+=k*j;
			kk-=k;
		}
		if(!kk)
		{
			mn=min(mn,z);
		}
	}
	printf("%lld\n",mn);
}