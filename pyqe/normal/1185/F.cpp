#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,fq[1<<9],dp[1<<9];
pair<long long,long long> mne[1<<9][2];

int main()
{
	long long i,j,ii,mm,k,w,mk,mkk;
	pair<pair<long long,long long>,pair<long long,long long>> mxe={{-1e18,-1e18},{-1,-1}};
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&mm);
		mk=0;
		for(j=0;j<mm;j++)
		{
			scanf("%lld",&k);
			mk+=1<<k-1;
		}
		fq[mk]++;
	}
	for(mk=0;mk<1<<9;mk++)
	{
		for(mkk=mk;1;mkk=(mkk-1&mk))
		{
			dp[mk]+=fq[mkk];
			if(!mkk)
			{
				break;
			}
		}
		for(ii=0;ii<2;ii++)
		{
			mne[mk][ii]={1e18,-1};
		}
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&w,&mm);
		mk=0;
		for(j=0;j<mm;j++)
		{
			scanf("%lld",&k);
			mk+=1<<k-1;
		}
		for(ii=0;ii<2;ii++)
		{
			if(w<=mne[mk][ii].fr)
			{
				for(j=1;j>ii;j--)
				{
					swap(mne[mk][j],mne[mk][j-1]);
				}
				mne[mk][ii]={w,i};
				break;
			}
		}
	}
	for(i=0;i<1<<9;i++)
	{
		for(j=i;j<1<<9;j++)
		{
			if(mne[i][0].sc!=-1&&mne[j][i==j].sc!=-1)
			{
				mxe=max(mxe,{{dp[i|j],-mne[i][0].fr-mne[j][i==j].fr},{mne[i][0].sc,mne[j][i==j].sc}});
			}
		}
	}
	printf("%lld %lld\n",mxe.sc.fr,mxe.sc.sc);
}