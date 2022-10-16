#include <bits/stdc++.h>

using namespace std;

long long n,ps[1000069],dp[1000069];
bitset<1000069> a;

int main()
{
	long long i,k,mn=1e18,z=0;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]=='(';
		ps[i]=ps[i-1]+a[i]*2-1;
	}
	for(i=1;i<=n;i++)
	{
		dp[i]=min(dp[i-1],ps[i]);
	}
	for(i=n;i;i--)
	{
		mn=min(mn,ps[i]);
		k=(a[i]*2-1);
		if(ps[n]-k*2==0&&!dp[i-1]&&mn-k*2==0)
		{
			z++;
		}
	}
	printf("%lld\n",z);
}