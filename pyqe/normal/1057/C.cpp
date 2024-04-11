#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,ma=50,dp[69][2069],inf=1e18;
pair<pair<long long,long long>,long long> as[69];

int main()
{
	long long i,j,r,k,l,z=inf;
	char ch;
	
	scanf("%lld%lld%lld",&n,&as[0].sc,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&as[i].fr.fr);
		as[i].sc=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		as[i].fr.sc=(ch=='G')+2*(ch=='B');
	}
	sort(as+1,as+n+1);
	as[0].fr.sc=-1;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=d+ma;j++)
		{
			dp[i][j]=inf;
		}
	}
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		k=as[i].fr.fr;
		l=as[i].sc;
		for(j=0;j<i;j++)
		{
			if(as[j].fr.fr<k&&as[j].fr.sc!=as[i].fr.sc)
			{
				for(r=k;r<=d+ma;r++)
				{
					dp[i][r]=min(dp[i][r],dp[j][r-k]+abs(as[j].sc-l));
					if(r>=d)
					{
						z=min(z,dp[i][r]);
					}
				}
			}
		}
	}
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}