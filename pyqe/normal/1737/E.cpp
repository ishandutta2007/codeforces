#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,dp[1000069],ps[1000069],sq[1000069],pwk;

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
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			ps[i]=ps[i-1];
			if(i==1)
			{
				dp[i]=2;
			}
			else
			{
				dp[i]=(ps[i-1]+dv-ps[max(i-(n+1-i-1)-1,0ll)])%dv;
			}
			ps[i]=(ps[i]+dp[i])%dv;
			z=dp[i]*pw(2,(n+1-i)/2)%dv;
			sq[i]=z*pw(pw(2,n),dv-2)%dv;
		}
		for(i=n;i;i--)
		{
			printf("%lld\n",sq[i]);
		}
	}
}