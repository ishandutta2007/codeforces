#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],ps[200069],dp[2],pwk,dv=1e9+7;

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

int main()
{
	long long i,z=0;
	char ch;
	
	scanf("%lld",&n);
	ps[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		if(ch!='?')
		{
			a[i]=ch-'a';
		}
		else
		{
			a[i]=-1;
		}
		ps[i]=ps[i-1]*(1+2*(a[i]==-1))%dv;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==-1||a[i]==2)
		{
			z=(z+dp[1]*ps[n]%dv*pw(ps[i],dv-2))%dv;
		}
		dp[1]=dp[1]*(1+2*(a[i]==-1))%dv;
		if(a[i]==-1||a[i]==1)
		{
			dp[1]=(dp[1]+dp[0])%dv;
		}
		dp[0]=dp[0]*(1+2*(a[i]==-1))%dv;
		if(a[i]==-1||!a[i])
		{
			dp[0]=(dp[0]+ps[i-1])%dv;
		}
	}
	printf("%lld\n",z);
}