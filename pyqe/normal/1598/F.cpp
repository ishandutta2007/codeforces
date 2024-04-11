#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,nn[20],a[20][400069],sm[20],mn[20],dp[1ll<<20];

int main()
{
	long long i,j,k,w,mk,mk2,c,z=0;
	string s;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		nn[i]=s.length();
		for(j=1;j<=nn[i];j++)
		{
			k=(long long)(s[j-1]=='(')*2-1;
			sm[i]+=k;
			mn[i]=min(mn[i],sm[i]);
			if(sm[i]==mn[i])
			{
				a[i][-sm[i]]++;
			}
		}
	}
	for(mk=1;mk<1ll<<n;mk++)
	{
		dp[mk]=-inf;
	}
	for(mk=0;mk<1ll<<n;mk++)
	{
		c=0;
		for(i=0;i<n;i++)
		{
			c+=sm[i]*(mk>>i&1);
		}
		for(i=0;i<n;i++)
		{
			if(!(mk>>i&1))
			{
				mk2=mk|1ll<<i;
				if(c+mn[i]>=0)
				{
					dp[mk2]=max(dp[mk2],dp[mk]+a[i][-mn[i]]*(c+mn[i]==0));
				}
				else
				{
					w=dp[mk];
					if(c>=0)
					{
						w+=a[i][c];
					}
					z=max(z,w);
				}
			}
		}
	}
	z=max(z,dp[(1ll<<n)-1]);
	printf("%lld\n",z);
}