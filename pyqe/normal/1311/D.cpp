#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long a[4];
pair<long long,long long> dp[4][20069];

int main()
{
	long long t,rr,i,j,r,p,mn,e;
	pair<long long,long long> mne;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=3;i;i--)
		{
			scanf("%lld",a+i);
		}
		mne={1e18,-1};
		for(i=1;i<=20000;i++)
		{
			dp[0][i]={0,0};
		}
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=20000;j++)
			{
				dp[i][j]={1e18,-1};
				for(r=j;r<=20000;r+=j)
				{
					dp[i][j]=min(dp[i][j],{dp[i-1][r].fr,r});
				}
				dp[i][j].fr+=abs(a[i]-j);
				if(i==3)
				{
					mne=min(mne,{dp[i][j].fr,j});
				}
			}
		}
		mn=mne.fr;
		e=mne.sc;
		printf("%lld\n",mn);
		for(i=3,p=e;i;p=dp[i][p].sc,i--)
		{
			printf("%lld%c",p," \n"[i==1]);
		}
	}
}