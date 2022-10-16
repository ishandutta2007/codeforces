#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,a[2069],wg[2069],dsu[1069],dp[1069][1069];
vector<long long> cc[1069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,j,r,sz,k,l,p,z=-1e18;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",wg+i);
		dsu[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		cc[i].push_back(0);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		dsu[fd(l)]=fd(k);
	}
	for(i=1;i<=n;i++)
	{
		cc[fd(i)].push_back(i);
		wg[n+fd(i)]+=wg[i];
		a[n+fd(i)]+=a[i];
		cc[i].push_back(n+i);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=d;j++)
		{
			dp[i][j]=-1e18;
		}
	}
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		sz=cc[i].size();
		for(j=0;j<sz;j++)
		{
			p=cc[i][j];
			for(r=wg[p];r<=d;r++)
			{
				dp[i][r]=max(dp[i][r],dp[i-1][r-wg[p]]+a[p]);
			}
		}
		if(i==n)
		{
			for(j=0;j<=d;j++)
			{
				z=max(z,dp[i][j]);
			}
		}
	}
	printf("%lld\n",z);
}