#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,m,fc[569],ifc[569],dp[569][569],pwk;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

inline long long cb(long long x,long long y)
{
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long i,j,r,ml;
	
	scanf("%lld%lld",&n,&m);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i>1)
			{
				if(j<=i-1)
				{
					dp[i][j]=pw(j,i);
				}
				else
				{
					ml=1;
					for(r=0;r<i;r++)
					{
						dp[i][j]=(dp[i][j]+dp[i-r][j-(i-1)]*cb(i,r)%dv*ml)%dv;
						ml=ml*(i-1)%dv;
					}
					dp[i][j]=(dp[i][j]+ml)%dv;
				}
			}
		}
	}
	printf("%lld\n",dp[n][m]);
}