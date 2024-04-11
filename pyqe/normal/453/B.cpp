#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,fz[69],sq[169];
pair<long long,long long> dp[169][1<<16];

int main()
{
	long long i,j,mk,k,c=0;
	pair<long long,long long> mne={1e18,-1};
	
	for(i=2;i<=53;i++)
	{
		if(!fz[i])
		{
			for(j=i;j<=53;j+=i)
			{
				fz[j]|=1<<c;
			}
			c++;
		}
	}
	scanf("%lld",&n);
	for(i=0;i<=n;i++)
	{
		for(mk=0;mk<1<<16;mk++)
		{
			dp[i][mk]={1e18,-1};
		}
	}
	dp[0][0]={0,0};
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for(mk=0;mk<1<<16;mk++)
		{
			for(j=1;j<=53;j++)
			{
				if((fz[j]&mk)==fz[j])
				{
					dp[i][mk]=min(dp[i][mk],{dp[i-1][mk^fz[j]].fr+abs(k-j),j});
				}
			}
			if(i==n)
			{
				mne=min(mne,{dp[i][mk].fr,mk});
			}
		}
	}
	mk=mne.sc;
	for(i=n;i;i--)
	{
		sq[i]=dp[i][mk].sc;
		mk^=fz[dp[i][mk].sc];
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}