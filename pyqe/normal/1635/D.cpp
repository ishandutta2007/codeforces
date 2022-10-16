#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,d,a[200069],dp[200069],ps[200069];

int main()
{
	long long i,k,p,c,z=0;
	bool bad;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	ps[0]=1;
	for(i=1;i<=d;i++)
	{
		dp[i]=dp[i-1];
		if(i>=2)
		{
			dp[i]=(dp[i]+dp[i-2])%dv;
		}
		ps[i]=(ps[i-1]+dp[i])%dv;
	}
	for(i=1;i<=n;i++)
	{
		bad=0;
		for(k=a[i];k;)
		{
			if(k%2)
			{
				k/=2;
			}
			else if(k%4==0)
			{
				k/=4;
			}
			else
			{
				break;
			}
			p=lower_bound(a+1,a+n+1,k)-a;
			if(p<=n&&a[p]==k)
			{
				bad=1;
				break;
			}
		}
		if(!bad)
		{
			for(c=0,k=a[i];k;k/=2,c++);
			if(c<=d)
			{
				z=(z+ps[d-c])%dv;
			}
		}
	}
	printf("%lld\n",z);
}