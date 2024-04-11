#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,sq[169],inf=1e18;
pair<pair<long long,long long>,long long> a[169];
pair<long long,bool> dp[169][169];
bitset<169> spc;

int main()
{
	long long t,rr,i,j,k,l,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&l,&k);
			a[i]={{k,l},i};
			spc[i]=0;
		}
		sort(a+1,a+n+1);
		for(i=1;i<=d;i++)
		{
			dp[0][i].fr=-inf;
		}
		dp[0][0].fr=0;
		for(i=1;i<=n;i++)
		{
			k=a[i].fr.fr;
			l=a[i].fr.sc;
			for(j=0;j<=d;j++)
			{
				dp[i][j]={dp[i-1][j].fr+k*(d-1),0};
				if(j)
				{
					dp[i][j]=max(dp[i][j],{dp[i-1][j-1].fr+k*(j-1)+l,1});
				}
			}
		}
		for(p=d,i=n;i;i--,p-=l)
		{
			k=a[i].sc;
			l=dp[i][p].sc;
			if(l)
			{
				sq[p]=k;
				spc[k]=1;
			}
		}
		printf("%lld\n",n+(n-d));
		for(i=1;i<=d-1;i++)
		{
			printf("%lld ",sq[i]);
		}
		for(i=1;i<=n;i++)
		{
			if(!spc[i])
			{
				printf("%lld %lld ",i,-i);
			}
		}
		printf("%lld\n",sq[d]);
	}
}