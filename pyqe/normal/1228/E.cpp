#include <bits/stdc++.h>

using namespace std;

long long n,d,dp[269][269],pwk,fc[269],pwd[269],pwd1[269],cbd[269][269],dv=1e9+7;

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

int main()
{
	long long i,j,r,k,kk;
	
	scanf("%lld%lld",&n,&d);
	fc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
	}
	for(i=0;i<=n;i++)
	{
		pwd[i]=pw(d,i);
		pwd1[i]=pw(d-1,i);
		for(j=0;j<=i;j++)
		{
			cbd[i][j]=cb(i,j);
		}
	}
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(r=0;r<=j;r++)
			{
				k=pwd[j-r];
				if(!r)
				{
					k=(k+dv-pwd1[j-r])%dv;
				}
				kk=dp[i-1][j-r]*k%dv*cbd[n-j+r][r]%dv*pwd1[n-j]%dv;
				dp[i][j]=(dp[i][j]+kk)%dv;
			}
		}
	}
	printf("%lld\n",dp[n][n]);
}