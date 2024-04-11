#include <bits/stdc++.h>

using namespace std;

long long n,dp[200069],ps[200069],pwk,dv=998244353;

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
	long long i;
	
	scanf("%lld",&n);
	dp[0]=1;
	ps[0]=1;
	dp[1]=1;
	ps[1]=1;
	for(i=2;i<=n;i++)
	{
		dp[i]=ps[i-1];
		ps[i]=(ps[i-2]+dp[i])%dv;
	}
	printf("%lld\n",dp[n]*pw(pw(2,n),dv-2)%dv);
}