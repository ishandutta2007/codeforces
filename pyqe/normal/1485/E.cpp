#include <bits/stdc++.h>

using namespace std;

long long n,d,pr[200069],dh[200069],a[200069],ax[200069],an[200069],dp[200069],inf=1e18;
vector<long long> al[200069],vl[200069];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	d=max(d,dh[x]);
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dh[l]=dh[x]+1;
		dfs(l);
	}
}

bool cmp(long long x,long long y)
{
	return a[x]<a[y];
}

int main()
{
	long long t,rr,i,j,ii,u,k,sz,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
		}
		for(i=2;i<=n;i++)
		{
			scanf("%lld",pr+i);
			al[pr[i]].push_back(i);
		}
		d=0;
		dfs(1);
		for(i=0;i<=d;i++)
		{
			vl[i].clear();
			ax[i]=-inf;
			an[i]=inf;
		}
		for(i=1;i<=n;i++)
		{
			vl[dh[i]].push_back(i);
		}
		for(i=2;i<=n;i++)
		{
			scanf("%lld",a+i);
			ax[dh[i]]=max(ax[dh[i]],a[i]);
			an[dh[i]]=min(an[dh[i]],a[i]);
		}
		z=0;
		for(i=1;i<=d;i++)
		{
			sort(vl[i].begin(),vl[i].end(),cmp);
			sz=vl[i].size();
			for(j=0;j<sz;j++)
			{
				k=vl[i][j];
				dp[k]=dp[pr[k]]+max(ax[i]-a[k],a[k]-an[i]);
			}
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				mx=-inf;
				for(j=(sz-1)*ii;j+1&&j<sz;j+=u)
				{
					k=vl[i][j];
					mx=max(mx,dp[pr[k]]+a[k]*-u);
					dp[k]=max(dp[k],mx+a[k]*u);
					z=max(z,dp[k]);
				}
			}
		}
		printf("%lld\n",z);
	}
}