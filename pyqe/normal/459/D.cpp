#include <bits/stdc++.h>

using namespace std;

long long n,a[1000069],dp[2][1000069],am[1000069],fw[1000069];
unordered_map<long long,long long> fr;

int main()
{
	long long i,p,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		fr[a[i]]++;
		dp[0][i]=fr[a[i]];
	}
	for(i=0;i<n;i++)
	{
		dp[1][i]=fr[a[i]]-dp[0][i]+1;
		am[dp[1][i]]++;
		for(p=dp[1][i];p<=1000000;p+=p&-p)
		{
			fw[p]++;
		}
	}
	for(i=0;i<n;i++)
	{
		am[dp[1][i]]--;
		for(p=dp[1][i];p<=1000000;p+=p&-p)
		{
			fw[p]--;
		}
		for(p=dp[0][i]-1;p>0;p-=p&-p)
		{
			z+=fw[p];
		}
	}
	printf("%lld\n",z);
}