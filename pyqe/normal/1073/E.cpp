#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long d,a[18],dp[2][2][2][2][1ll<<10];

long long val(long long x)
{
	long long i,j,ii,jj,mk,*tg,*tg2,ml=1e18,z=0;
	
	for(i=17;i+1;i--)
	{
		a[i]=x%10;
		x/=10;
	}
	dp[0][0][0][0][0]=1;
	for(i=0;i<18;i++)
	{
		ml/=10;
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				for(mk=0;mk<1ll<<10;mk++)
				{
					for(j=0;j<=(!jj?a[i]:9);j++)
					{
						tg=&dp[0][1][ii||j][jj||j<a[i]][mk|(j||ii)<<j];
						tg2=&dp[1][1][ii||j][jj||j<a[i]][mk|(j||ii)<<j];
						*tg=(*tg+dp[0][0][ii][jj][mk])%dv;
						*tg2=(*tg2+dp[1][0][ii][jj][mk]+j*ml%dv*dp[0][0][ii][jj][mk])%dv;
					}
				}
			}
		}
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				for(mk=0;mk<1ll<<10;mk++)
				{
					dp[0][0][ii][jj][mk]=dp[0][1][ii][jj][mk];
					dp[1][0][ii][jj][mk]=dp[1][1][ii][jj][mk];
					dp[0][1][ii][jj][mk]=0;
					dp[1][1][ii][jj][mk]=0;
				}
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(jj=0;jj<2;jj++)
		{
			for(mk=0;mk<1ll<<10;mk++)
			{
				if(__builtin_popcountll(mk)<=d)
				{
					z=(z+dp[1][0][ii][jj][mk])%dv;
					dp[0][0][ii][jj][mk]=0;
					dp[1][0][ii][jj][mk]=0;
				}
			}
		}
	}
	return z;
}

int main()
{
	long long k,l;
	
	scanf("%lld%lld%lld",&k,&l,&d);
	printf("%lld\n",(val(l)+dv-val(k-1))%dv);
}