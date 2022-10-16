#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=1e4;
long long n,dp[6][3][2];
pair<long long,long long> a[6];

int main()
{
	long long i,j,r,k,l,p;
	double z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i]={k,l};
	}
	for(i=1;i<=ma;i++)
	{
		dp[0][0][0]=1;
		for(j=1;j<=n;j++)
		{
			k=a[j].fr;
			l=a[j].sc;
			for(r=0;r<3;r++)
			{
				for(p=0;p<2;p++)
				{
					dp[j][r][p]=dp[j-1][r][p]*max(min(i-1,l)-k+1,0ll);
					if(r)
					{
						dp[j][r][p]+=dp[j-1][r-1][p]*(i>=k&&i<=l);
						if(r==2)
						{
							dp[j][r][p]+=dp[j-1][r][p]*(i>=k&&i<=l);
						}
					}
					if(p)
					{
						dp[j][r][p]+=dp[j-1][r][p-1]*max(l-max(i+1,k)+1,0ll);
					}
				}
			}
		}
		z+=(double)(dp[n][2][0]+dp[n][1][1]+dp[n][2][1])*i;
	}
	for(i=1;i<=n;i++)
	{
		k=a[i].fr;
		l=a[i].sc;
		z/=l-k+1;
	}
	printf("%.20lf\n",z);
}