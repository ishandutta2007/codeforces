#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7,inf=1e18;
long long n[2],a[2][1069],dp[1069],dp2[1069];
bitset<1069> spc;

int main()
{
	long long t,rr,i,j,ii,l;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			cin>>s;
			n[ii]=s.length();
			for(i=1;i<=n[ii];i++)
			{
				a[ii][i]=s[i-1]-'a';
			}
		}
		for(i=1;i<=n[0]-n[1]+1;i++)
		{
			for(j=1;j<=n[1];j++)
			{
				if(a[0][i-1+j]!=a[1][j])
				{
					break;
				}
			}
			spc[i]=j>n[1];
		}
		dp2[0]=1;
		for(i=1;i<=n[0]-n[1]+1;i++)
		{
			dp[i]=dp[i-1];
			dp2[i]=dp2[i-1];
			if(spc[i])
			{
				dp[i]=inf;
				dp2[i]=0;
				for(j=max(i-n[1]+1,1ll);j<=i;j++)
				{
					if(spc[j])
					{
						l=max(j-n[1],0ll);
						dp[i]=min(dp[i],dp[l]+1);
					}
				}
				for(j=max(i-n[1]+1,1ll);j<=i;j++)
				{
					if(spc[j])
					{
						l=max(j-n[1],0ll);
						if(dp[l]+1==dp[i])
						{
							dp2[i]=(dp2[i]+dp2[l])%dv;
						}
					}
				}
			}
		}
		l=max(n[0]-n[1]+1,0ll);
		printf("%lld %lld\n",dp[l],dp2[l]);
	}
}