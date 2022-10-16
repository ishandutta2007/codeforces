#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[2][200069],dp[200069][4];

int main()
{
	long long t,rr,i,ii,mn,mx,mk,mk2,mk3,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mn=inf;
		mx=-inf;
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf(" %c",&ch);
				a[ii][i]=ch=='*';
				if(a[ii][i])
				{
					mn=min(mn,i);
					mx=max(mx,i);
				}
			}
		}
		for(i=0;i<=n;i++)
		{
			for(mk=1;mk<4;mk++)
			{
				dp[i][mk]=inf;
			}
		}
		dp[mn-1][3]=-1;
		for(i=mn;i<=mx;i++)
		{
			mk=(long long)a[0][i]|(long long)a[1][i]<<1;
			for(mk2=1;mk2<4;mk2++)
			{
				if((mk2&mk)==mk)
				{
					for(mk3=1;mk3<4;mk3++)
					{
						if(mk3&mk2)
						{
							dp[i][mk2]=min(dp[i][mk2],dp[i-1][mk3]+__builtin_popcountll(mk2));
						}
					}
				}
			}
		}
		z=inf;
		for(mk=1;mk<4;mk++)
		{
			z=min(z,dp[mx][mk]);
		}
		printf("%lld\n",z);
	}
}