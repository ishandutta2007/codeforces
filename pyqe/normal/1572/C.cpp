#include <bits/stdc++.h>

using namespace std;

long long n,a[3069],pst[3069],dp[3069][3069];
vector<long long> vl[3069];

int main()
{
	long long t,rr,i,j,r,k,sz,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			vl[i].clear();
		}
		z=n-1;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			z-=i-1&&a[i]==a[i-1];
			sz=vl[a[i]].size();
			vl[a[i]].push_back(i);
			pst[i]=sz;
		}
		for(i=0;i<=n;i++)
		{
			for(j=i;j;j--)
			{
				dp[j][i]=dp[j][i-1];
				for(r=pst[i]-1;r+1&&vl[a[i]][r]>=j;r--)
				{
					k=vl[a[i]][r];
					if(a[k+1]!=a[k]&&a[i-1]!=a[i])
					{
						dp[j][i]=max(dp[j][i],dp[k+1][i-1]+1+dp[j][k]);
					}
				}
			}
			dp[i+1][i]=0;
		}
		printf("%lld\n",z-dp[1][n]);
	}
}