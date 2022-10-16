#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ma=1e5,fq[100069],dp[100069],pwk,dv=1e9+7;

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
	long long i,j,k,c;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(i=ma;i;i--)
	{
		c=0;
		for(j=i;j<=ma;j+=i)
		{
			c+=fq[j];
			dp[i]=(dp[i]+dv-dp[j])%dv;
		}
		dp[i]=(dp[i]+pw(2,c)-1)%dv;
	}
	printf("%lld\n",dp[1]);
}