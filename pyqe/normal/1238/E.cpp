#include <bits/stdc++.h>

using namespace std;

long long n,am[20][20],d[1<<20][20],dp[1<<20],nn;

int main()
{
	long long i,j,ln,k,l,mk,mkk;
	string s;
	
	scanf("%lld%lld",&ln,&n);
	nn=(1<<n)-1;
	cin>>s;
	for(i=1;i<ln;i++)
	{
		k=s[i-1]-'a';
		l=s[i]-'a';
		am[k][l]++;
		am[l][k]++;
	}
	for(mk=1;mk<1<<n;mk++)
	{
		for(i=0;i<n;i++)
		{
			if(mk&(1<<i))
			{
				mkk=mk-(1<<i);
				for(j=0;j<n;j++)
				{
					d[mk][j]=d[mkk][j]+am[i][j];
				}
				break;
			}
		}
	}
	for(mk=1;mk<1<<n;mk++)
	{
		dp[mk]=1e18;
		k=__builtin_popcount(mk);
		for(i=0;i<n;i++)
		{
			if(mk&(1<<i))
			{
				mkk=mk-(1<<i);
				dp[mk]=min(dp[mk],dp[mkk]+k*(d[mkk][i]-d[nn-mk][i]));
			}
		}
	}
	printf("%lld\n",dp[nn]);
}