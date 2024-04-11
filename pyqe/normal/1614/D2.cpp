#include <bits/stdc++.h>

using namespace std;

const int ma=2e7;
int n,npm=0,fq[20000069],fq2[20000069],apm[20000069];
bitset<20000069> vpm;
long long dp[20000069];

int main()
{
	int i,j,k;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		fq[k]++;
	}
	for(i=ma;i;i--)
	{
		for(j=i;j<=ma;j+=i)
		{
			fq2[i]+=fq[j];
		}
	}
	for(i=2;i<=ma;i++)
	{
		if(!vpm[i])
		{
			npm++;
			apm[npm]=i;
			if(i<=ma/i)
			{
				for(j=i*i;j<=ma;j+=i)
				{
					vpm[j]=1;
				}
			}
		}
	}
	for(i=ma;i;i--)
	{
		for(j=1;j<=npm;j++)
		{
			k=i*apm[j];
			if(k>ma)
			{
				break;
			}
			dp[i]=max(dp[i],dp[k]-(long long)i*fq2[k]);
		}
		dp[i]+=(long long)i*fq2[i];
	}
	printf("%lld\n",dp[1]);
}