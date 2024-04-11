#include <bits/stdc++.h>

using namespace std;

long long n,a[300069],dv=1e9+7,fc[600069],pwk,dp[10][300069],cnt[300069];

long long pw(long long x,long long y)
{
	if(y==0)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2==1)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

long long cb(long long x,long long y)
{
	if(x<y)
	{
		return 0;
	}
	return fc[x]*pw(fc[y]*fc[x-y]%dv,dv-2)%dv;
}

long long bf(long long x,long long y)
{
	if(y>300000)
	{
		return 0;
	}
	if(dp[x][y]==-1)
	{
		long long i;
		
		dp[x][y]=cb(cnt[y],x);
		for(i=y+y;i<=300000;i+=y)
		{
			dp[x][y]=(dp[x][y]+dv-bf(x,i))%dv;
		}
	}
	return dp[x][y];
}

int main()
{
	long long i,j;
	
	fc[0]=1;
	for(i=1;i<=300000;i++)
	{
		fc[i]=fc[i-1]*i%dv;
	}
	for(i=1;i<10;i++)
	{
		for(j=1;j<=300000;j++)
		{
			dp[i][j]=-1;
		}
	}
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(j=1;j*j<=a[i];j++)
		{
			if(a[i]%j==0)
			{
				cnt[j]++;
				if(j!=a[i]/j)
				{
					cnt[a[i]/j]++;
				}
			}
		}
	}
	for(i=1;1;i++)
	{
		if(i>7||bf(i,1)>0)
		{
			break;
		}
	}
	if(i>7)
	{
		i=-1;
	}
	printf("%lld\n",i);
}