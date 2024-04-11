#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,dp[16777216];
pair<int,int> a[25];

int pyt(int p,int q)
{
	return (a[p].fr-a[q].fr)*(a[p].fr-a[q].fr)+(a[p].sc-a[q].sc)*(a[p].sc-a[q].sc);
}

int main()
{
	int i,mk,j,mkk,mkkk,c=0,k;
	
	scanf("%d%d",&a[0].fr,&a[0].sc);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].fr,&a[i].sc);
	}
	for(mk=0;mk<1<<n;mk++)
	{
		dp[mk]=1e9;
	}
	dp[0]=0;
	for(mk=0;mk<(1<<n)-1;mk++)
	{
		for(i=1;mk&1<<i-1;i++);
		mkk=mk+(1<<i-1);
		dp[mkk]=min(dp[mkk],dp[mk]+pyt(0,i)+pyt(i,0));
		for(j=i+1;j<=n;j++)
		{
			if(mk&1<<j-1)
			{
				continue;
			}
			mkkk=mkk+(1<<j-1);
			dp[mkkk]=min(dp[mkkk],dp[mk]+pyt(0,i)+pyt(i,j)+pyt(j,0));
		}
	}
	printf("%d\n0",dp[(1<<n)-1]);
	for(mk=(1<<n)-1;mk>0;)
	{
		for(i=n;i>0;i--)
		{
			if(!(mk&1<<i-1))
			{
				continue;
			}
			mkk=mk-(1<<i-1);
			if(dp[mkk]==dp[mk]-pyt(0,i)-pyt(i,0))
			{
				mk=mkk;
				printf(" %d 0",i);
				continue;
			}
			for(j=i+1;j<=n;j++)
			{
				if(!(mk&1<<j-1))
				{
					continue;
				}
				mkkk=mkk-(1<<j-1);
				if(dp[mkkk]==dp[mk]-pyt(0,i)-pyt(i,j)-pyt(j,0))
				{
					mk=mkkk;
					printf(" %d %d 0",i,j);
					break;
				}
			}
		}
	}
	printf("\n");
}