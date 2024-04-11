#include <bits/stdc++.h>

using namespace std;

long long n,m,cr,dsu[1069],ls[1069],zs=0,inf=1e18;
vector<long long> al[1069];
pair<long long,long long> dp[1069],sq[1069];

#define mp make_pair
#define fr first
#define sc second

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

pair<long long,long long> dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	pair<long long,long long> mx={0,x},tmp;
	
	ls[x]=cr;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(ls[l]<cr)
		{
			tmp=dfs(l);
			tmp.fr++;
			mx=max(mx,tmp);
		}
	}
	return mx;
}

int main()
{
	long long i,k,l,e,z;
	pair<long long,long long> mxe={-inf,-1};
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
		dp[i]={inf,-1};
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
		dsu[fd(l)]=fd(k);
	}
	for(i=1;i<=n;i++)
	{
		cr=i;
		dp[fd(i)]=min(dp[fd(i)],{dfs(i).fr,i});
	}
	for(i=1;i<=n;i++)
	{
		if(fd(i)==i)
		{
			mxe=max(mxe,dp[i]);
		}
	}
	e=mxe.sc;
	for(i=1;i<=n;i++)
	{
		if(fd(i)==i)
		{
			l=dp[i].sc;
			if(l!=e)
			{
				al[e].push_back(l);
				al[l].push_back(e);
				zs++;
				sq[zs]={e,l};
			}
		}
	}
	cr=n+1;
	z=dfs(1).sc;
	cr=n+2;
	z=dfs(z).fr;
	printf("%lld\n",z);
	for(i=1;i<=zs;i++)
	{
		k=sq[i].fr;
		l=sq[i].sc;
		printf("%lld %lld\n",k,l);
	}
}