#include <bits/stdc++.h>

using namespace std;

long long n,lb[200069],rb[200069],dp[200069],ps[200069],pwk,dv=1e9+7;

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
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",lb+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",rb+i);
		dp[i]=max(min(rb[i],rb[i-1])-max(lb[i],lb[i-1])+1,0ll)*pw((rb[i]-lb[i]+1)*(rb[i-1]-lb[i-1]+1)%dv,dv-2)%dv;
		ps[i]=(ps[i-1]+1+dv-dp[i])%dv;
		z=(z+1+dv-dp[i])%dv;
		if(i-1)
		{
			z=(z+(ps[i-2]*(1ll+dv-dp[i])+1+dv-dp[i]+dv-dp[i-1]+max(min({rb[i],rb[i-1],rb[i-2]})-max({lb[i],lb[i-1],lb[i-2]})+1,0ll)*pw((rb[i]-lb[i]+1)*(rb[i-1]-lb[i-1]+1)%dv*(rb[i-2]-lb[i-2]+1)%dv,dv-2))*2)%dv;
		}
	}
	printf("%lld\n",z);
}