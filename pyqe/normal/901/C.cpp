#include <bits/stdc++.h>

using namespace std;

long long n,m,nr[300069],dsu[300069],mn[300069],mx[300069],dp[300069],ps[300069],inf=1e18;
vector<long long> al[300069];
bitset<300069> vtd,vtd2;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void bgt(long long x,long long ls)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(l==ls)
		{
			continue;
		}
		if(!vtd[l])
		{
			nr[l]=nr[x]+1;
			bgt(l,x);
		}
		if(vtd2[fd(l)]&&nr[fd(l)]<=nr[fd(x)])
		{
			dsu[fd(x)]=fd(l);
		}
	}
	vtd2[x]=0;
}

long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long t,rr,i,k,l,p,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
		mn[i]=inf;
		mx[i]=-inf;
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			bgt(i,0);
		}
	}
	for(i=1;i<=n;i++)
	{
		mn[fd(i)]=min(mn[fd(i)],i);
		mx[fd(i)]=i;
	}
	for(i=1;i<=n;i++)
	{
		if(fd(i)==i&&mn[i]!=mx[i])
		{
			dp[mx[i]]=max(dp[mx[i]],mn[i]);
		}
	}
	for(i=1;i<=n;i++)
	{
		dp[i]=max(dp[i],dp[i-1]);
		ps[i]=ps[i-1]+dp[i];
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		p=lower_bound(dp+k,dp+l+1,k)-dp-1;
		z=tri(l)-tri(k-1)-(ps[l]-ps[p]+(k-1)*(p-k+1));
		printf("%lld\n",z);
	}
}